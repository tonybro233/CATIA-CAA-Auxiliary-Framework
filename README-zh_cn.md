[![CATIA](https://img.shields.io/badge/CATIA-V6-green.svg)](https://www.3ds.com)
[![3DEXP](https://img.shields.io/badge/3DEXPERIENCE-R2017x-brightgreen.svg)]()
[![VS](https://img.shields.io/badge/VisualStudio-2012-lightgrey.svg)]()
[![OS](https://img.shields.io/badge/OS-win64-blue.svg)]()

# CAA开发通用Framework
在CAA的开发中, 'framework' 是开发框架代码结构的第二层，一般来说CAA的代码按顺序分为3层: 

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

这个仓库提供了3个通用的Framework，如果你想要使用它，需要把这些源代码放入你自己的 workspace 然后进行编译即可。 

### UtilityFW

这个framework包含了两个module。CommonFuncMod提供了一些通用的静态方法，这些方法根据它们自身的功能被分到了5个class文件中。CommonToolMod主要放置一些通用的工具类。

- CommonFuncMod
  - GeneralEnhancement
  - PartEnhancement
  - PLMEnhancement
  - StringEnhancement
  - TopologyEnhancement

- CommonToolMod
  - CsvReader

### ExternalAppFW

这个Framework意在提供对外在应用程序的控制. 现在它能支持控制Microsoft Excel(Office14 x86) 和连接SQL Server数据库。

### VisTempRepFW

如果你需要开发某些需要__使用并选择__临时元素的功能，那么你必须要创建一些实现了特定接口的组件(CAA使用 Component Object Model组件对象模型)。这个框架为你做完了上述的繁琐工作，引入这个framework就可以使用操控临时元素。（临时元素是指在CATIA中临时辅助用的图形元素，比如选择方向时的箭头等）

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

这个Framework提供了5种临时图形元素类型：

- WireBox （线框盒）
- Circle（圆弧）
- FixedArrow（固定箭头）
- Point（点）
- Text（文字）

