#pragma once

//STD
#include <iostream>
#include <string>
#include <filesystem>
#include <numbers> 
#include <functional>

//SFML
#include <SFML/Graphics.hpp>

//Breakout
#include "Game.h"
#include "Utils/Utils.h"
#include "Entity.h"

//Tweening
#include "Utils/Tweeners/Tweener.h"
#include "Utils/Tweeners/PositionTweener.h"
#include "Utils/Tweeners/ScaleTweener.h"
#include "Utils/Easings.h"

//Systems
#include "System/RenderSystem.h"
#include "System/TweeningSystem.h"

//Components
#include "Components/Component.h"
#include "Components/Renderable.h"
