// Engine.cpp

#include "Engine.h"

void Engine::executeProgram(MoveProgram* program)
{
    // move by move
    for (int m = 0; m < program->getMoveCount(); m++)
    {
        // which move
        switch (program->getMove(m))
        {
            case MOVE_RIGHT:
                turn90Degrees(1);
                break;
            case MOVE_LEFT:
                turn90Degrees(-1);
                break;
            case MOVE_FORWARD:
                moveStraight(1);
                break;
            case MOVE_BACKWARD:
                moveStraight(-1);
                break;
        }
    }
}

// EOF
