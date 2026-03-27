---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-09 09:52::03 AM
tags:
  - Cpp
  - WebAssembly
  - CMake
  - Conan
---
# [**drogon**](https://drogon.org/) 
Drogon, the fast C++ web framework
Run your application anywhere, knowing it is as fast as it could be.

## Controller
The controller is very important in web application development. This is where we will define our URLs, which HTTP methods are allowed, which [filters](https://drogonframework.github.io/drogon-docs/#/ENG/ENG-05-Middleware-and-Filter) will be applied and how requests will be processed and responded to.
- Drogon have three types controllers, `HttpSimpleController`, `HttpController`, and `WebSocketController`.
```cpp
class MyClass:public drogon::HttpSimpleController<MyClass>
{
public:
    //TestController(){}
    virtual void asyncHandleHttpRequest(const HttpRequestPtr &req,
                                         std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
    PATH_ADD("/json");
    PATH_LIST_END
};
```

# main
`drogon::app().setIndexPage("index.html");`: Set the default page for the root path "/" 
`drogon::app().setDocumentRoot("./");`: Point to where your HTML files are.
`rogon::app().addListener("0.0.0.0", 5555).run();` : Port and ip to listen.






# Specific Task
## Set default page.
### method 1:
**Use :**
- Bast in case of dynamic website or with multiple directories. 
`controller.h`
```cpp
class Controller : public drogon::HttpSimpleController<Controller> {
  public:
	  void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
    // 1. Keep your existing mapping
    PATH_ADD("/hello", Get); 
    
    // 2. Add the ROOT mapping
    // This captures the homepage "http://localhost:5555/"
    PATH_ADD("/", Get); 
    PATH_LIST_END
};
```
`controller.cc`
```cpp
void HelloController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) { 
	// Check if the user is visiting the root "/"
	if (req->path() == "/") { 
		// Create a Redirect Response (302 Found) 
		// This tells the browser to go to "/hello" immediately 
		auto resp = HttpResponse::newHttpRedirectResponse("/hello"); callback(resp); 
		return; 
	} 
	
	// --- Your Original Logic for /hello --- 
	Json::Value musicData; 
	musicData["song_title"] = "Cyberpunk Vibes"; 
	musicData["status"] = "playing"; 
	
	auto resp = HttpResponse::newHttpJsonResponse(musicData); 
	callback(resp); 
}
```

### method 2:
**Use :**
- bast for static or single page website.
`main.cc`
```cpp
int main() {
    // Set the default page for the root path "/"
    drogon::app().setIndexPage("index.html");
    
    // Make sure you point to where your HTML files are
    drogon::app().setDocumentRoot("./"); 
    
    drogon::app().addListener("0.0.0.0", 5555).run();
    return 0;
}
```

## next
