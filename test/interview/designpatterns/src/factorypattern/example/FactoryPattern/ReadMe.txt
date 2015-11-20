========================================================================
    CONSOLE APPLICATION : FactoryPattern Project Overview
========================================================================

AppWizard has created this FactoryPattern application for you.  

This file contains a summary of what you will find in each of the files that
make up your FactoryPattern application.


FactoryPattern.vcproj
    This is the main project file for VC++ projects generated using an Application Wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

FactoryPattern.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named FactoryPattern.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

/*××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××
×××××××××××××××××××××××××设计模式源码说明××××××××××××××××××××××
×× 1. 编写此源码的目：网上虽然可以看到许多设计模式的源码，但是大多
×× 都是分散的、WEB的，很少能看到所有常用模式源码的汇总，因此小弟抽
×× 了闲暇时间编写了这些模式的C++实现，并以注释形式或输出说明形式加
×× 入了小弟的一些个人见解，一来是总结个人对设计模式的认识，二是为初
×× 学者提供一些建议和参考，当然小弟的认识有可能太片面希望各位采用批
×× 判态度对待之，以免有误人子弟之嫌。
××
×× 2. 本代码全部在VS2005下调试功能。
××
×× 3. 全部代码为 Seasky（http://Seasky.cnblogs.com/）独立编写
××
×× 4. 欢迎各位以各种形式转载，但是不希望看到把代码原封不动转载，而
×× 重新标识源码作者，这里只是希望尊重小弟的劳动
××
×× 5. 热烈欢迎各种途径于小弟进行交流 
××    Blog:  http://Seasky.cnblogs.com/
××    Eamil: hj007@sina.com   Seasky_cn@163.com
××    QQ:21948008  MSN:Seasky_cn@163.com
××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××*/
补充说明：
为了加强大家对简单工厂模式、工厂模式、和抽象工厂模式的深入理解，小弟在
这里把这三种模式放在了一起，以便大家比较。