1、有点怀疑的代码
搜索leader
src\units\drawer.cpp:59
unit_drawer::redraw_unit
    const std::string ellipse_top = formatter() << ellipse << "-" << leader << nozoc << selected << "top.png~RC(ellipse_red>" << tc << ")";//drawer.cpp:216，路径是"image/misc/ellipse-top.png~RC(ellipse_red>red)"
	const std::string ellipse_bot = formatter() << ellipse << "-" << leader << nozoc << selected << "bottom.png~RC(ellipse_red>" << tc << ")";//drawer.cpp:217，"misc/ellipse-bottom.png~RC(ellipse_red>red)"

1.1、删掉文件后的错误打印。leader脚下没有了光环
20210201 22:37:41 error display: could not open image 'misc/ellipse-leader-top.png'
20210201 22:37:41 error display: could not open image 'misc/ellipse-leader-bottom.png'
20210201 22:37:43 error display: could not open image 'misc/ellipse-hero-top.png'
20210201 22:37:43 error display: could not open image 'misc/ellipse-hero-bottom.png'
20210201 22:37:51 error display: could not open image 'misc/ellipse-leader-selected-top.png'
20210201 22:37:51 error display: could not open image 'misc/ellipse-leader-selected-bottom.png'

src\picture.cpp
    ERR_DP << "could not open image '" << loc.get_filename() << "'" << std::endl; //582
2、
src\units\udisplay.cpp