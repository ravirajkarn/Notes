---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-24 16:49::43 PM
tags:
  - Cpp
  - WebAssembly
---
# step 1: setup llvm.
Linux: `sudo apt-get install clang lld`
# Step 2: Create cpp file
```CPP
// main.cpp
extern "C" {
    int add(int a, int b) {
        return a + b;
    }
}
```

# Step 3: Compile to Web Assembly
**File Name:** `.wasm`

```bash
clang++ --target=wasm32 -nostdlib -Wl,--no-entry -Wl,--export-all -o main.wasm ./hello.cpp
```

**Flags Explained:**
- `--target=wasm32`: Specifies the WebAssembly 32-bit architecture.
- `-nostdlib`: Tells the compiler not to use standard libraries, as they are not available by default in raw Wasm.
- `-Wl,--no-entry`: Informs the linker there is no `main()` entry point.
- `-Wl,--export-all`: Exports all functions (like `add`) so they are visible to JavaScript. 
# Step 4: create HTML file

```html
<!DOCTYPE html>
<html>
<body>
  <script>
    WebAssembly.instantiateStreaming(fetch('main.wasm'))
      .then(obj => {
        const { add } = obj.instance.exports;
        console.log("Result from Wasm:", add(10, 20));
      });
  </script>
</body>
</html>
```

# Step 5: running the program.
1. Check the Developer Console
Press **F12** (or `Ctrl+Shift+I`) and click the **Console** tab. 
- If everything is working, you should see: `Result from Wasm: 30`.
- If you see an error like `404 Not Found` or `MIME type error`, proceed to the steps below. 

2. Run a Local Web Server (Required)

> [!warning]
> You **cannot** open the `index.html` file by double-clicking it from your folder. Browsers block WebAssembly requests from `file://` URLs for security reasons. You must serve the files via `http://`. 

Use any of these quick commands in your project folder:

- **Python:** `python3 -m http.server 8000`
- **Node.js:** `npx serve`
- **VS Code:** Install the **Live Server** extension and click "Go Live" at the bottom right.
Then, visit `http://localhost:8000` in your browser.