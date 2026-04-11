---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-31 01:08::56 AM
tags:
  - Header
  - include
  - Cpp
  - Library
  - audio
---

# FAAD2

## Introduction
This header is use for decoding the `.m4a` file. `.m4a` is future of `.mp3`.



> [!summary] The Big Picture 🧩
> We have covered all the essential pieces for a Raw AAC (ADTS) player:
> 1. **`NeAACDecOpen`**: Get a handle.
> 2. **`NeAACDecInit`**: Read the first frame's header to configure the decoder.
> 3. **`NeAACDecDecode`**: Loop through the file, turning compressed data into `(short*)` PCM audio.
> 4. **`NeAACDecClose`**: Clean up.

## headers:
### 1. `neaacdec.h` (The Standard) ✅
- **Use for:** All modern FAAD2 implementations.
- **Why:** This is the official API header for FAAD2. It contains the definitions for `NeAACDecHandle`, `NeAACDecOpen`, and `NeAACDecDecode`.
- **Origin:** The name comes from "Nero AAC Decoder," as the code was originally developed based on the Nero reference code.

### 2. `faad.h` (The Relic) ❌
- **Use for:** Very old versions of the library (FAAD1 or early FAAD2 builds).
- **Why it exists:** You might see it referenced in ancient tutorials (10+ years old) or legacy codebases.
- **Current status:** In most modern source trees of FAAD2, this file either doesn't exist or is just a "shim" (a dummy file) that includes `neaacdec.h` internally to prevent old code from breaking.
## Use
**Step 1:**
we need to ask the library to allocate memory for this handle. The function to do this is `NeAACDecOpen()`.
``` Cpp
NeAACDecHandle hDecoder = NeAACDecOpen();
```
**Step 2:**
> [!question] How `NeAACDecInit` Works?
> Since you don't have a separate "metadata box" (like in MP4), this function acts like a scout. It scans the raw data you provide, looks for the sync word (the start of a frame), and reads the header to figure out the audio format.
```Cpp
long NeAACDecInit(NeAACDecHandle hDecoder,
                  unsigned char *pData,
                  unsigned long ulDataSize,
                  unsigned long *pRate,
                  unsigned char *pChannels);
```
**The Parameters**
1. **`pData`**: This is a pointer to your buffer containing the AAC data. You pass the raw bytes here.
2. **`ulDataSize`**: The size of that buffer.
3. **`pRate` & `pChannels`**: These are **output** parameters. The function will write the sample rate (e.g., 44100) and channel count (e.g., 2) into these variables so your program knows what it's dealing wit

**Step 3:**
Once initialized, the `hDecoder` handle is ready for action. Now we need to enter a loop where we feed it compressed data and get back raw PCM audio.

The function to decode a frame is **`NeAACDecDecode`**.
```Cpp
void* NeAACDecDecode(NeAACDecHandle hDecoder,
                     NeAACDecFrameInfo *hInfo,
                     unsigned char *buffer,
                     unsigned long buffer_size);
```

> [!success] The Return Value
> Notice that it returns a `void*`. This pointer points to the internal buffer where the library has stored the raw, uncompressed audio (PCM).

### The Missing Number
We have the data, but we need to know **how much** data we actually have so we don't read past the end of the buffer (which would crash the program).
```Cpp
typedef struct NeAACDecFrameInfo
{
    unsigned long bytesconsumed;
    unsigned long samples;
    unsigned char channels;
    unsigned char error;
    unsigned long samplerate;
    unsigned char sbr;
    unsigned char object_type;
    unsigned char header_type;
    unsigned char num_front_channels;
    unsigned char num_side_channels;
    unsigned char num_back_channels;
    unsigned char num_lfe_channels;
    unsigned char channel_position[64];
    unsigned char ps;
} NeAACDecFrameInfo;
```
The `samples` field in the `NeAACDecFrameInfo` struct tells you exactly how many individual numbers (integers) are valid in that buffer.

**A Critical Detail:** This number represents the **total** samples across _all_ channels.
- If you have **Stereo** audio (2 channels) and the decoder outputs 1024 frames, `samples` will be **2048**.
- The data is usually "interleaved," meaning it looks like: `[Left, Right, Left, Right, ...]`

**Step 4:**
```Cpp
void NeAACDecClose(NeAACDecHandle hDecoder);
```
 

>![[Conan/FAAD2]] 

