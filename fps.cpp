#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "fps.hpp"
#ifdef HAVE_SDL_H
#include <SDL.h>
#endif

FPS::FPS()
  : next_ticks(0)
  , frames(0)
  , latest_frames(0)
{
}

void FPS::update()
{
  ++frames;
  uint32_t now = SDL_GetTicks();
  if (now > next_ticks) {
    latest_frames = frames;
    frames = 0;
    next_ticks += 1000;
  }
}