#ifndef __TEXTRENDERER_CARDACE_H_
#define __TEXTRENDERER_CARDACE_H_

#include <GL/glew.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

class Glyph {
public:
  Glyph(char c, int a, int mny, int mxy, int mnx, int mxx, GLuint tex) {
    letter = c;
    advance = a;
    maxx = mxx;
    maxy = mxy;
    minx = mnx;
    miny = mny;
    texture = tex;
  }

  char getChar() const { return letter; };
  int getTextureID() const { return texture; };
  int getAdvance() const { return advance; };
  int getMaxY() const { return maxy; };
  int getMaxX() const { return maxx; };
  int getMinX() const { return minx; };
  int getMinY() const { return miny; };

private:
  char letter;
  GLuint texture;
  int advance;
  int maxx;
  int maxy;
  int minx;
  int miny;
};

class TextRenderer {
public:
  TextRenderer(char *fontPath, unsigned int fontSize);
  void renderChar(char letter, int x, int y);
  void renderText(char *str, int x, int y);
  int getWidth(const char *str); // width of the rendered text in pixels
  int getHeight();
  void quit();

private:
  void initTextures();
  Glyph &getGlyph(std::size_t idx) { return glyphs.at(idx - 0x20); };

  std::vector<Glyph> glyphs;
  TTF_Font *font;
  int outline;
  int fontHeight;
  /* Use reference counting to init and quit the TTF library */
  static unsigned int referenceCounter;
};

#endif
