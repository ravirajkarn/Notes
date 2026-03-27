---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-12 12:58::01 PM
tags:
  - Library
  - lib
  - audio
  - Cpp
  - C
---

# [miniaudio](https://github.com/mackron/miniaudio.git)

## Introduction
It is audio playing library. Understand the working of audio in devices. Audio is wave like sine theta and more. 

> [!tip] Tips
> - `ma_decoder` : It is use to for uncompromising the file or playing.
> - `ma_engine` : Used for mixing like decoding two file or play two audio.
> - `ma_sound` : Use for 3D sound.

## 🎯 The Low Level API
We need to understand the **`Data Callback`**. 
- Audio hardware "pulls" data from you.
Think of the audio device as a hungry beast 🦁 that wakes up hundreds of times a second.
1. It wakes up and shouts, **"I need 480 frames of audio right now!"**
2. It calls your **callback function**.
3. Your function must instantly fill a **bucket** (buffer) with exactly that much audio data.
4. If you are too slow, the beast "starves," and you hear a nasty click or pop (this is called a **"buffer underrun"**).
```CPP
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) { 
	// We need to fill 'pOutput' with audio data here. 
}
```

> [!tldr] ma_devide* pDevice
> - 

> [!tldr] void* pOutput
> - This is where we put data we want to send **OUT** to the speakers.(**Bucket**)
> - Pointer type **void\***.

> [!tip] Tip
> `void*` is a **"Universal Container."**

> [!tldr] const void* pInput
> - This contains data coming **IN** from a microphone (capture mode).
> - Constant type pointer **void\***.

> [!tldr] ma_uint32 frameCount
> - how many "frames" of audio the device wants.


> [!info] `#define MINIAUDIO_IMPLEMENTATION`
> `#define MINIAUDIO_IMPLEMENTATION`: It is important to include in the program to run the code as entire code is define inside it. Or, use `include "miniaudio.cpp"` instead 


> [!example] Example
> In this example we are creating sound with sine function.(hello world in sound)
> ```CPP
> #define MINIAUDIO_IMPLEMENTATION
> #include "miniaudio.h"
> #include <cmath>
> #include <iostream>
> 
> // 1. Define our custom struct to hold the wave state
> struct SineWave {
> 	double frequency;
> 	double sampleRate;
> 	double phase;
> };
> 
> // 2. The Callback: Called by miniaudio when it needs more sound
> void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
> 	// Retrieve our custom data
> 	SineWave* data = (SineWave*)pDevice->pUserData;
> 	float* pOut = (float*)pOutput;
> 	
> 	for (ma_uint32 i = 0; i < frameCount; ++i) {  
> 		// Calculate the sine value for the current phase
> 		float currentSample = (float)sin(data->phase);
> 		
> 		// Write to output buffer (Interleaved: Left, Right, Left, Right...)
> 		pOut[i * 2]     = currentSample;  // Left Channel
> 		pOut[i * 2 + 1] = currentSample;  // Right Channel
> 		
> 		// Advance the phase for the next sample
> 		// Formula: NewPhase = OldPhase + (2 * PI * Freq / SampleRate)
> 		data->phase += (2.0 * 3.14159 * data->frequency) / data->sampleRate;
> 		
> 		// Reset phase if it completes a full circle (optional, prevents huge numbers)
> 		if (data->phase > 2.0 * 3.14159) {
> 			data->phase -= 2.0 * 3.14159;
> 		}
> 	}
> }
> 
> int main() {
> 	// Initialize our custom data struct
> 	SineWave waveData;
> 	waveData.frequency = 440.0; // 440 Hz (A4 note)
> 	waveData.sampleRate = 48000.0;
> 	waveData.phase = 0.0;
> 	// Configure the device
> 	ma_device_config config = ma_device_config_init(ma_device_type_playback);
> 	config.playback.format   = ma_format_f32; // Floating point audio
> 	config.playback.channels = 2;             // Stereo
> 	config.sampleRate        = 48000;         // Must match our struct
> 	config.dataCallback      = data_callback; // Point to our function
> 	config.pUserData         = &waveData;     // Pass our custom struct!
> 	
> 	ma_device device;
> 	if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
> 		std::cout << "Failed to initialize device." << std::endl;
> 		return -1;
> 	}
> 	
> 	// Start playing
> 	ma_device_start(&device);
> 	
> 	std::cout << "Playing 440Hz Sine Wave... Press Enter to quit." << std::endl;
> 	std::cin.get(); // Wait for user input
> 	
> 	// Cleanup
> 	ma_device_uninit(&device);
> 	return 0;
> }
> ```

### Working with files
We need **decoder** to turn compressed MP3 data back to raw PCM audio.
- ma_decoder handles the file like WAV, FLAC and MP3.
```cpp
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
ma_result ma_decoder_init_file(const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
```

> [!tldr] const char* pFilePath
> - This is where you will give file to read. i.e. song.mp3

> [!tldr] const ma_decoder_config* pConfig
> - this where we set or play with decoder configuration. usually set to `NULL`

> [!tldr] ma_decoder* pDecoder
> `pDecoder` is the pointer to the object that manages the open file.

Now we need to bridge the gap. We need to take audio from the decoder and put it into the output buffer so the speakers can play it.
```cpp
ma_decoder_read_pcm_frames(ma_decoder* pDecoder, void* pFramesOut, ma_uint64 frameCount, ma_uint64* pFramesRead);
```

> [!tldr] ma_decoder* pDecoder
> The file we are reading from.

> [!tldr] void* pFramesOut
> The destination buffer where the audio data goes.

> [!tldr] const ma_uint64 frameCount
> How many frames we want to read.

> [!tldr] ma_uint64* pFramesRead

> [!example] Example
> In this example we are creating sound with sine function.(hello world in sound)
> ```CPP
> #define MINIAUDIO_IMPLEMENTATION
> #include "miniaudio.h"
> #include <cmath>
> #include <iostream>
> 
> // 1. Define our custom struct to hold the wave state
> struct SineWave {
> 	double frequency;
> 	double sampleRate;
> 	double phase;
> };
> 
> struct AudioPlayer {
> 	ma_decoder decoder;
> };
> 
> void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
> 	// 1. Get our custom player object
> 	AudioPlayer* player = (AudioPlayer*)pDevice->pUserData;
> 	
> 	// 2. Read audio from the file directly into the output buffer
> 	ma_uint64 framesRead;
> 	ma_decoder_read_pcm_frames(&player->decoder, pOutput, frameCount, &framesRead);
> 	
> 	(void)pInput; // Unused
> }
> 
> int main() {
> 	// 1. Initialize our custom player wrapper
> 	AudioPlayer player;
> 	
> 	// 2. Load the file into the decoder
> 	// We pass NULL for the config to use default settings
> 	ma_result result = ma_decoder_init_file("music.mp3", NULL, &player.decoder);
> 	if (result != MA_SUCCESS) {
> 		printf("Could not load file: music.mp3\n");
> 		return -1;
> 	}
> 	
> 	// 3. Configure the Device
> 	ma_device_config config = ma_device_config_init(ma_device_type_playback);
> 	config.playback.format   = player.decoder.outputFormat; // Match the file's format
> 	config.playback.channels = player.decoder.outputChannels; // Match the file's channels
> 	config.sampleRate        = player.decoder.outputSampleRate; // Match the file's rate
> 	config.dataCallback      = data_callback;
> 	config.pUserData         = &player; // Pass our player object to the callback!
> 	
> 	// 4. Initialize the Device
> 	ma_device device;
> 	if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
> 		printf("Failed to open playback device.\n");
> 		ma_decoder_uninit(&player.decoder); // distinct cleanup for the decoder
> 		return -1;
> 	}
> 	
> 	// 5. Start Playback
> 	ma_device_start(&device);
> 	printf("Press Enter to quit...\n");
> 	getchar();
> 	
> 	// 6. Cleanup
> 	ma_device_uninit(&device);
> 	ma_decoder_uninit(&player.decoder);
> 	
> 	return 0;
> } 
> ```

These two functions work together like **opening a book** and then **reading the pages**.

Here is the breakdown of the difference:

> [!question] What is the Difference between ma_decoder_init_file and ma_decoder_read_pcm_frames?
> ### 1. `ma_decoder_init_file` (The Setup 🛠️)
This function is the **"Open"** command. You call it **once** at the very beginning. 
>  - **What it does:** It looks for the file on your hard drive, opens it, reads the header (to check if it's MP3, WAV, FLAC, etc.), and sets up the internal "cursor" to the start of the music.
>  - **Analogy:** Picking a book off the shelf and opening it to page 1.
>  - **Key Inputs:** The filename (e.g., `"music.mp3"`) and a pointer to your `ma_decoder` variable.
>  
>  ### 2. `ma_decoder_read_pcm_frames` (The Action 🏃)
This function is the **"Read"** command. You call it **repeatedly** inside a loop.
>  - **What it does:** It grabs a specific chunk of audio data (frames), decodes it into raw sound (PCM) that the computer can hear, and puts it into a buffer. Then, it moves the internal cursor forward.
>  - **Analogy:** Reading one sentence, then the next, then the next.
>  - **Key Inputs:** The `ma_decoder` variable (from step 1) and a buffer (that `void*` "box"!) to store the sound.
>  - ---
>  ### Comparison Table
>
> | **Feature**       | **ma_decoder_init_file**          | **ma_decoder_read_pcm_frames**        |
> | ----------------- | --------------------------------- | ------------------------------------- |
> | **When to call?** | **Once**, at the start.           | **Many times**, usually in a loop.    |
> | **Main Job**      | Prepare the file & parse headers. | Decode actual audio data.             |
> | **Returns**       | `ma_result` (Success/Fail).       | `ma_uint64` (Number of frames read).  |
> | **Logic**         | "Is this file valid?"             | "Give me the next 1 second of audio." |


## 🎯 High-Level Engine
While the Low-Level API gives you ultimate control, it can be a lot of work. Imagine if you wanted to play **two** sound effects at once (like a footstep and background music).

In your current code, you would have to:
1. Open two decoders.
2. Read data from both.
3. Mathematically add the samples together (`sampleA + sampleB`) inside the callback.
4. Watch out for "clipping" (if the sum goes above 1.0).

This gets messy fast! 😫

- `miniaudio` provides a **High-Level Engine** (`ma_engine`) that handles all of this mixing for you. It's much easier to use—often just one line of code to play a sound.

`ma_engine_init(const ma_engine_config* pConfig, ma_engine* pEngine)`

initialising the engine is incredibly simple:
```CPP
ma_engine engine;
ma_result result = ma_engine_init(NULL, &engine);
```

Now for the best part. To play a sound, we don't need to **open a decoder, create a callback**, or manage buffers. **The engine has a "fire and forget" function**:
```CPP
ma_engine_play_sound(ma_engine* pEngine, const char* pFilePath, ma_sound_group* pGroup);
```

```Cpp
int main(int argc, char* argv[]){
	try
	{
		if (argc < 2){
			logger("player")->critical("less argument");
		}
		std::filesystem::path music = argv[1];
		ma_engine engine;
		ma_result result = ma_engine_init(NULL, &engine);
		ma_engine_play_sound(&engine, music.c_str(), NULL);
		
		std::getchar();
		ma_engine_uninit(&engine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
```

### 3D Spatial Audio
Now that we can play simple 2D sounds, let's look at **Spatialization**. This is crucial for games. We want sounds to have a "location" in the world—like a zombie groaning behind you or a waterfall to your right.

To do this, `miniaudio` needs to know two things:
1. Where the **Listener** (the player) is.
2. Where the **Sound** is
If we are in a standard 3D world (X, Y, Z coordinates), and the listener is standing at the center (0, 0, 0).
![[licensed-image.png|500x500]] 
To control a specific sound, we create an `ma_sound` object.

Here is how we initialize it so it's ready to play (but doesn't play yet):
```cpp
ma_sound_init_from_file(ma_engine* pEngine, const char* pFilePath, ma_uint32 flags, ma_sound_group* pGroup, ma_sound* pSound);
```

`ma_sound_start(&effect)` is exactly how you trigger the sound to play.

Now, remember our goal: we want this sound to come from the **right side** of the player (Coordinate X = 1.0).

Since we now have our `effect` object initialized, we can modify it. `miniaudio` uses a very consistent naming scheme for changing properties, usually starting with `ma_sound_set_...`.

position of sound.
```cpp
ma_sound_set_position(&effect, 1.0f, 0.0f, 0.0f);
```

Position of listener.
```cpp
ma_engine_listener_set_position(ma_engine* pEngine, ma_uint32 listenerIndex, float x, float y, float z);
```

> [!warning]
> This sets the listener for the **entire audio world**, not just for that one specific sound effect.

- **Negative Z (-):** In front of you (Forward)    
- **Positive Z (+):** Behind you (Backward)