[![CATIA](https://img.shields.io/badge/CATIA-V6-green.svg)](https://www.3ds.com)
[![3DEXP](https://img.shields.io/badge/3DEXPERIENCE-R2017x-brightgreen.svg)]()
[![VS](https://img.shields.io/badge/VisualStudio-2012-lightgrey.svg)]()
[![OS](https://img.shields.io/badge/OS-win64-blue.svg)]()

# Common framework for CAA development
In CAA development, 'framework' is the second level of code structure, there are basically three levels in order: 

- Workspace

- Framework

- Module

```
Workspace
├── Framework
│   └── CNext/
│   └── IdentityCard/
│   └── PrivateInterfaces
│   └── ProtectedInterfaces
│   └── PublicInterfaces
│   └── Module.m/
│   	└── LocalInterfaces/
│   	└── src/
│   	└── Imakefile.mk
│   └── Module2.m/
│   └── ...
├── Framework2
├── Framework3
├── ...
```

This repository provide three frameworks for common usage, if you want to use it, just put the source files into your own workspace and build it. 

### UtilityFW

This framework has two modules. CommonFuncMod provides static common methods, and these methods are divided into five files according to their functions. CommonToolMod is designed to provide instrument classes.

- CommonFuncMod
  - GeneralEnhancement
  - PartEnhancement
  - PLMEnhancement
  - StringEnhancement
  - TopologyEnhancement

- CommonToolMod
  - CsvReader

### ExternalAppFW

This framework aims to provide ability to control external application. Now it can support Microsoft Excel(Office14 x86) and connection to SQL Server.

### VisTempRepFW

If you want to develop some tools which will __use and select temporary component__, you have to create some components implement specified interface(CAA use Component Object Model). This framework has done the fussy works for you, and you just have to import it.

```cpp
// ======== include
#include "JNCITempFixArrowRep.h"

// ======== member   
private:
	JNCITempFixArrowRep		* _zArrow;
	JNCITempFixArrowRep		* _xArrow;
	JNCITempFixArrowRep		* _yArrow;

// ======== constructor 
YourCommand::YourCommand():
{
    ::CATInstantiateComponent("JNCTempFixArrowRepComp",IID_JNCITempFixArrowRep,(void**)&_zArrow);
    ::CATInstantiateComponent("JNCTempFixArrowRepComp",IID_JNCITempFixArrowRep,(void**)&_xArrow);
    ::CATInstantiateComponent("JNCTempFixArrowRepComp",IID_JNCITempFixArrowRep,(void**)&_yArrow);	
}
```

This framework has provided five  kinds of temporary graphic components:

- WireBox
- Circle
- FixedArrow
- Point
- Text

