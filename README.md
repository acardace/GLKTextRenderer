# GLKTextRenderer
##Description
First, K stands for KISS.

I have written these snippets of code out of necessity for an OpenGL project at University, the requirements were simple, I needed something easy and clean to use having as dependencies only SDL2 and OpenGL (I was not allowed to use other libraries) to render text on-screen in real-time.

Short story, if you want to render text in real-time with only OpenGL and SDL2 there's no clean way to do it.
Long story, what you basically have to do is for any text you want to render, creating a texture of it and load it into the GPU memory, after that you can render it. Of course if you try to do it with text such as a timer content or simply rapidly changing text it kills your performance.

Said that I needed something simple and quick to render text in real-time.
GLKTextRenderer does nothing else than creating an atlas of chars, for every char in your font creates a texture and loads it in the GPU memory ready to be rendered, it does this once, after that it's just assembling the right glyphs needed to render the requested text.

To do what just described above you just need to initialize a TextRenderer object
```C++
char fontPath[] = "font.ttf";
TextRenderer title(fontPath, 24);
```
After that you can render any rapidly changing text in real-time
```C++
char text[] = "Hello World!";
// text -> text to be rendered
//500   -> x coord
//500   -> y coord
title.renderText(text, 500, 500);
```
You can also center it
```C++
title.renderText(text, 500 - title.getWidth(text), 500 - title.getWidth(text));
```
when you're done
```C++
title.close()
```
The init and close methods will init and close the TTF library provided by SDL2, there is reference counting so it willonly be done when is needed.
##Sharing
This code was useful for me I hope it might be the same for anyone who has the same requirements, so if you make any use of it, improve it or just like it let me know! I'll be very glad to know it.
##Packaging and Installation
I did not write any CMake or Makefile to build and install a shared library and I may never write it but if you're willing to do it you're welcome! The same goes for packaging.

##Results

------------------------------------------------------------

Copyright **Antonio Cardace** 2016, antonio@cardace.it
