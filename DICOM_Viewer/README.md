# 开发一个显示DICOM图像的小软件

在开始这个小任务之前，建议大家先阅读[DICOM简介](../Digital_Imaging_and_Communication_in_Medicine/DICOM.md)，了解基本的DICOM知识。

在我们的日常工作中，DICOM图像浏览器是一个很重要的工具，最常用的免费DICOM浏览器有：[RadiAnt](https://www.radiantviewer.com/)、[ezDicom](https://sourceforge.net/projects/ezdicom/)等。大家可以先安装感受一下它们有哪些功能。

+ 动手做
> 编写一个小程序，使用之前编译出的[DCMTK](../Third_Party_Library/README.md)开发包，实现从硬盘打开某个文件夹下的所有DICOM图像进行显示，并可以上下翻页，以及平移旋转缩放。
> 示例DICOM文件已经放在Image文件夹内。