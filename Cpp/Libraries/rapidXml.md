---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-14 13:18::12 PM
tags:
  - Cpp
  - Library
  - xml
---

# rapidXml 
rapidXml is a fastest DOM parsing tool. It is use to edit XML file.
## Load an file
```cpp
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <vector>

int main(){
	rapidxml::file<> xmlFile("demo.xml");
	std::vector<char> buffer(xmlFile.data(),xmlFile.data()+xmlFile.size());
	buffer.push_back('\0');
	
	rapidxml::xml_document<> doc;
	doc.parse<0>(&buffer[0]);
	
}
```

> [!important] 
> - `xml_document` does **not** own the string. It only holds pointers to the buffer passed to it. If `std::vector<char>` or `std::string` goes out of scope, `xml_document` will be a garbage memory.
> - **The string must be mutable:** Put `\0` character into source string to separate names and values.

---
```cpp
xml_node<> *node = doc.first_node("foobar");
```
- If the XML is `<foobar>Hello</foobar>', then it find the node.
- If the XML is `<data><foobar>Hello</foobar></data>`, It will fail (return `nullptr`) as `foobar` is a child of `data`, not a direct child of the document.
