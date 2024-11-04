#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @class Animation
 * @brief A class representing an animation sequence.
 * 
 * An Animation consists of a sequence of frames and a duration 
 * which represents how long the animation lasts.
 */
class Animation
{
    public:
    /** @brief The starting frame of the animation. */
    unsigned int startFrame;

    /** @brief The ending frame of the animation. */
    unsigned int endFrame;

    /** @brief Duration of the animation in seconds. */
    float duration;

    /**
     * @brief Constructs an Animation with given start and end frames, and duration.
     * 
     * @param startFrame The starting frame of the animation.
     * @param endFrame The ending frame of the animation.
     * @param duration Duration of the animation in seconds.
     */
    Animation(unsigned int startFrame, unsigned int endFrame, float duration)
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }
    /**
     * @brief Get the length of the animation in frames.
     * 
     * @return The number of frames in the animation.
     */
    unsigned int getLength() { return endFrame - startFrame + 1; }
};
/**
 * @class AnimationHandler
 * @brief A class to handle multiple animations and control the current animation state.
 * 
 * This class stores multiple animations, manages updating frames based on 
 * time progression, and switching between animations.
 */
class AnimationHandler
{
    private:

    /** @brief Vector storing all animations added to the handler. */
    std::vector<Animation> animations;

    /** @brief Current time since the animation loop started. */
    float t;

    /** @brief Index of the currently active animation. */
    int currentAnim;

    public:

     /**
     * @brief Adds a new animation to the handler.
     * 
     * @param anim The animation to add.
     */
    void addAnim(Animation& anim);

    /**
     * @brief Updates the current frame of animation based on the elapsed time.
     * 
     * @param dt The time in seconds since the last update call.
     */
    void update(const float dt);

    /**
     * @brief Changes the active animation, resetting the time progression.
     * 
     * @param animNum The index of the new animation to activate.
     */
    void changeAnim(unsigned int animNum);

    /** @brief The current section of the texture that should be displayed. */
    sf::IntRect bounds;

    /** @brief Pixel dimensions of each individual frame in the animation. */
    sf::IntRect frameSize;

    /**
     * @brief Default constructor initializing variables.
     */
    AnimationHandler()
    {
        this->t = 0.0f;
        this->currentAnim = -1;
    }
    /**
     * @brief Constructor initializing frame size and setting default values.
     * 
     * @param frameSize The dimensions of each frame in pixels.
     */
    AnimationHandler(const sf::IntRect& frameSize)
    {
        this->frameSize = frameSize;

        this->t = 0.0f;
        this->currentAnim = -1;
    }
};

#endif /* ANIMATION_HANDLER_HPP */