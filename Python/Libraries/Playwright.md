---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-06-26 16:46::48 PM
tags:
  - python
  - webdev
---

# Playwright
It is Library which help in **web scraping**.

## Trace viewer

### Introduction

Playwright Trace Viewer is a GUI tool that lets you explore recorded Playwright traces of your tests meaning you can go back and forward though each action of your test and visually see what was happening during each action.

**You will learn**

- How to record a trace
- How to open the trace viewer

### Recording a trace

Traces can be recorded by running your tests with the `--tracing` flag.
```bash
pytest --tracing on
```

Options for tracing are:
- `on`: Record trace for each test
- `off`: Do not record trace. (default)
- `retain-on-failure`: Record trace for each test, but remove all traces from successful test runs.

### Opening the trace
You can open the saved trace using the Playwright CLI or in your browser on [`trace.playwright.dev`](https://trace.playwright.dev/). Make sure to add the full path to where your trace's zip file is located. Once opened you can click on each action or use the timeline to see the state of the page before and after each action. You can also inspect the log, source and network during each step of the test. The trace viewer creates a DOM snapshot so you can fully interact with it, open devtools etc.
```
playwright show-trace trace.zip
```
## Tools:
### Running Codegen
Use the `codegen` command to run the test generator followed by the URL of the website you want to generate tests for. The URL is optional and can be added directly in the browser window if omitted.
```bash
playwright codegen demo.playwright.dev/todomvc
```

## Running and debugging tests
### Introduction
You can run a single test, a set of tests or all tests. Tests can be run on one browser or multiple browsers by using the `--browser` flag. By default, tests are run in a headless manner, meaning no browser window will be opened while running the tests and results will be seen in the terminal. If you prefer, you can run your tests in headed mode by using the `--headed` CLI argument.

### Running tests
#### Command Line
To run your tests, use the `pytest` command. This will run your tests on the Chromium browser by default. Tests run in headless mode by default meaning no browser window will be opened while running the tests and results will be seen in the terminal.

```bash
pytest
```

#### Run tests in headed mode
To run your tests in headed mode, use the `--headed` flag. This will open up a browser window while running your tests and once finished the browser window will close.
``` bash
pytest --headed
```

#### Run tests on different browsers
To specify which browser you would like to run your tests on, use the `--browser` flag followed by the name of the browser.
```bash
pytest --browser webkit
```

To specify multiple browsers to run your tests on, use the `--browser` flag multiple times followed by the name of each browser
```bash
pytest --browser webkit --browser firefox
```
#### Run specific tests
To run a single test file, pass in the name of the test file that you want to run.
```bash
pytest test_login.py
```

To run a set of test files, pass in the names of the test files that you want to run.
```bash
pytest tests/test_todo_page.py tests/test_landing_page.py
```

To run a specific test, pass in the function name of the test you want to run.
```bash
pytest -k test_add_a_todo_item
```
## Functions:

> [!success] **goto()**
> **Input:** 
>- `url` str
>	URL to navigate page to. the url should include scheme.
>- `referer` str _(optional)_
>	Referer header value. If provided it will take preference over the referer header value set by **page.set_extra_http_headers()**,
>- `timeout` float _(optional)_
>	Maximum operation time in milliseconds, defaults to 30 seconds, pass `0` to disable timeout.
>- `wait_until` "load" | "domcontentloaded" | "networkidle" | "commit" _(optional)_
>
> **Output:**
> Returns the main resource response.
> - **NoneType** | **Response**
>
> **Action:** 
> It take you to the site where you want to perform an action.
> 
>**Through Error:** 
>- There's an SSL error
>- target URL invalid
>- the timeout is exceeded during navigation
>- the remote server dose not respond or unreachable
>- the main resource failed to load.

> [!success] **expect_response()**
> **Input:** 
> - `url_or_predicate` **str | Pattern | Callable\[Response\]**:bool
> 	Request URL string, regex or predicate receiving [Response](https://playwright.dev/python/docs/api/class-response "Response") object. When a [base_url](https://playwright.dev/python/docs/api/class-browser#browser-new-context-option-base-url) via the context options was provided and the passed URL is a path, it gets merged via the [`new URL()`](https://developer.mozilla.org/en-US/docs/Web/API/URL/URL) constructor.
> - `timeout` [float](https://docs.python.org/3/library/stdtypes.html#numeric-types-int-float-complex "float") _(optional)_[#](https://playwright.dev/python/docs/api/class-page#page-wait-for-response-option-timeout)
> 	Maximum wait time in milliseconds, defaults to 30 seconds, pass `0` to disable the timeout. The default value can be changed by using the [browser_context.set_default_timeout()](https://playwright.dev/python/docs/api/class-browsercontext#browser-context-set-default-timeout) or [page.set_default_timeout()](https://playwright.dev/python/docs/api/class-page#page-set-default-timeout) methods.
>
> **Output:**
>- **EventContextManager**
>
> **Action:** 
> Returns the matched response. See [waiting for event](https://playwright.dev/python/docs/events#waiting-for-event) for more details about events.
> 
>**Through Error:** 

> [!success] **all_text_contents()**
> **Input:** 
> 
> **Output:**
>- List [str]
>
> **Action:** 
> Returns an array of `node.textContent` values for all matching nodes.
> 
>**Through Error:** 
>

> [!success] **inner_text()**
> **Input:** 
> - the text you want to match with. It could be **str** | **Pattern** | **List[str]** | **List[Pattern] | List[str | Pattern]** 
> - ignore case **bool**
> - timeout **float**
> - use_inner_text **bool**
>
> **Output:**
>- **NoneType**
>
> **Action:** 
> It _ignores hidden text._ Furthermore, it normalizes white-space meaning. convert `&nbsp;` (`\xa0`) into normal spaces, and times the edges. 
> 
>**Through Error:** 

> [!success] **text_content()**
> **Input:** 
>- `timeout` *float* (optional) 
>	Maximum time in milliseconds. Defaults to 30000 (30 seconds). Pass 0 to disable timeout. The default value can be changed by using the browser_context.set_default_timeout() or page.set_default_timeout() methods.
> **Output:**
>- **NoneType | str**
>
> **Action:** 
> It Pulls all the text inside the element, including hidden text(like elements with `display: none`), and it preserves all the messy formatting, line breaks(`\n`), and non-breaking spaces(`\xa0`).
> 
>**Through Error:** 

> [!success] **to_have_text()**
> **Input:** 
> - `timeout` **float** _(optional)_
> 	Maximum time in milliseconds. Defaults to `30000` (30 seconds). Pass `0` to disable timeout. The default value can be changed by using the [browser_context.set_default_timeout()](https://playwright.dev/python/docs/api/class-browsercontext#browser-context-set-default-timeout) or [page.set_default_timeout()](https://playwright.dev/python/docs/api/class-page#page-set-default-timeout) methods.
>
> **Output:**
>- Returns the `element.innerText` | **str**
>
> **Action:** 
> It stare at an element for up to 5 seconds and wait for its text to match you provided. It automatically handles the race conditions of the web. By default, it normalizes white-space just like `inner_text()`, making it very forgiving.

- **Evaluating JavaScript** : You can evaluate java script and change content.
## Classes :
> [!success] **locator**
> **Input:** 
> - `selector` **str**   
> 	A selector to use when resolving DOM element.
> - `has` **Locator**
> 	Narrows down the results of the method to those which contain elements matching this
> 	relative locator
> - `has_not`**Locator** _(optional)_
> 	Matches elements that do not contain an element that matches an inner locator. Inner locator is queried against the outer one
> - `has_not_text`
> 	Matches elements that do not contain specified text somewhere inside, possibly in a child or a descendant element.
> - `has_text` **str** | **Pattern** _(optional)_
> 	Matches elements containing specified text somewhere inside, possibly in a child or a descendant element
> 	
> **Output:**
> - **Locator**
>
> **Action:** 
>  The method returns an element locator that can be used to perform actions on this page / frame. Locator is resolved to the element immediately before performing an action, so a series of actions on the same locator can in fact be performed on different DOM elements. That would happen if the DOM structure between those actions has changed.
> 
>**Through Error:** 
>

## Specific Code
### With headed launch
```ini
[pytest]
addopts = -v --browser chromium --headed --slowmo 2000
```