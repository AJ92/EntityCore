#ifndef VIEW_H
#define VIEW_H

#include "Common.h"

class Entity;

class View
{
public:

   static const size_t NONE = 0xFFFFFFFF;

   virtual void draw(Entity *e, void *drawState) = 0;

};

typedef void (*ViewFunctionPointer)(Entity *e, void *drawState);

class ViewFunction : public View
{
private:
   const ViewFunctionPointer function;

public:

   ViewFunction(ViewFunctionPointer function) 
      : function(function)
   {
   }

   void draw(Entity *e, void *drawState)
   {
      function(e, drawState);
   }

};

#endif