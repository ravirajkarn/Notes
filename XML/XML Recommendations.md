---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-13 08:43::24 AM
tags:
  - xml
---
# Role of XML Namespaces
```xml 
<?xml version="1.0" encoding="UTF-8"?>
<cat:catalog>
	<cat:table>
		<cat:size>
			<cat:length>2.0</cat:length>
			<cat:width>0.9</cat:width>
			<cat:height>1.2</cat:height>
		</cat:size>
		<cat:description>
			<xhtml:table>
				<xhtml:tr>
					<xhtml:td>This is a lovely table</xhtml:td>
					<xhtml:td>And this is a picture of it</xhtml:td>
				</xhtml:tr>
			</xhtml:table>
		</cat:description>
	</cat:table>
</cat:catalog>
```
- Here `cat` & `xhtml` are namespaces which allow us to use different same tag with different contest. Same as cpp.

## Adding Namespaces to XML Documents
The `cat` namespace can precede any element name, providing it is separated by a colon:
```xml
<cat:catalog>
```
## Adding Default Namespaces 
`xmlns` Keyword is define as default namespace.
It doesn't need to assign a prefix to elements within this namespace.

> [!EXAMPLE]
> ```xml
> <catalog xmlns="http://www.apress.com/ns/furniture" xmlns:xhtml="http://www.w3.org/1999/xhtml">
> ```

