---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-11 21:17::40 PM
tags:
  - xml
---
I am learning this from 
`Beginning XML with DOM and Ajax From NOvice to Professional` by Sas Jacobs.

It is very old technology but we are using it. It is time of `json` file. 

----
# Introduction

XML :  Extensible Markup Language 
- It same as HTML.
- It is designed for sanding data. 
- It don't have slandered tags. We can make tags.

## Structure of an XML Documents
- XML document is divided into two parts: 
	1. The prolog
	2. root element.
### The Prolog 
it XML declaration and a comment. 
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!-- This XML document comment --->
```
![[structure of an XML.png]]


## Naming Rules in XML
- XML names are case-sensitive
- It can't be a number.
- letter or underscore
- colons indicate namespaces in XML, don't include them within names. 
- XML names cannot start with a number or punctuation.
- XML names cannot include spaces.

## XML Document Prolog
It may contain the XML declaration, processing instructions, comments, and an embedded DTD or schema.
### XML Declaration
XML documents usually start with an XML declaration, ==It is optional:==
```XML
<?xml version="1.0" encoding="UTF-8"?>
```

The XML declaration may also include attributes that provide information about the version, encoding, and whether the document is standalone:

```XML
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
```

Current XML version is 1.1. However, many processors don't recognise this version. 
==default== the document use UTF-8 encoding.
each of the XML declaration is optional.

#### Processing Instructions
PIs start with the characters `<?` and finish with `?>`. They usually appear in the prolog,
although they can appear in other places within an XML document

> [!NOTE] 
> An XML declaration also starts with the characters `<?xml`. Even though the XML declaration looks similar, it’s worth remembering that it’s quite different from a PI.

The following PI indicates a reference to an XSL stylesheet: 
```xml
<?xml-stylesheet type="text/xsl" href="stylesheet.xsl"?>
```
The first item in a PI is a name, called the PI target. The preceding PI has the name xml-stylesheet. Names that start with xml are reserved for XML-specific PIs. The PI also has the text string type="text/xsl" href="stylesheet.xsl". Although this looks like two attributes, the content isn’t treated that way. You’ll see more examples of stylesheet PIs in Chapters 6 and 7.

#### Comments
```xml
<!-- Here is a omment -->
```


### DTDs and XML Schemas
DTDs and XML schemas provide rules about which elements and attributes can appear within the XML document.

## Understanding Sections Within the XML Document Element
### Elements
Elements include a starting and ending tag as well as content. The content can be text,
child elements, or both text and elements.
#### Empty Elements
```xml 
<elementName></elementName>
<elementName/>
```
#### Elements Containing Only Text
```xml
<genre>Classic</genre>
<name>Sumit Kumar</name>
```

#### Elements Containing Other Elements 
```xml
<details>
	<name>Sumit Kumar</name>
	<roll_no>35</roll_no>
</details>
```

#### Mixed Elements
```xml 
<mixedElement>This element contains both text and child elements
<childElement>This element contains text</childElement>
<emptyElement/>
</mixedElement>
```

### Attributes
- Attributes consists of name and value pairs, with the value enclosed in either double or single quotation marks:
```xml
<elementName attributeName="attributeValue"/>
```
Attributes provide additional information about an element:
```xml
<p style="text-align:center;">Introduction to XML</p>
```

### Text 
all text within an XML Document is contained inside opening and closing tags. Unless you mark the text as CDATA, It will be treated as if it were XML and processed accordingly.

### CDATA Sections
CDATA allows you to mark blocks of text so that they're not processed as XML.

```xml
<title><![CDATA[ Why 9 is < 10]]></title>
```
An application that reads data from a database and marks it up in XML might embed all content in CDATA sections to avoid the need to process the reserved characters explicitly. I’ll show you an example of using CDATA with JavaScript in Chapter 3.

### Entities
This will cause processing error.
```xml
<expression> 10 < 25 </expression>
```

the correct way is 
```xml
<expression> 10 &lt; 25 </expression>
```

![[xml_entity.png]]

you can add these as character entities using Unicode or hexadecimal numbers. For example, you can encode the copyright symbol © as &#169; or &#xA9;