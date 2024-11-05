#ifndef GUIENTRY_H
#define GUIENTRY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>
#include <string>

/**
 * @class GuiEntry
 * @brief Represents a single entry within a graphical user interface (GUI) component.
 *
 * A GuiEntry consists of a visual shape, a message string, and text displayed on the entry.
 * It is designed to be used as part of a larger GUI, such as a menu or list, where each entry
 * can display a label and carry an associated action or message.
 */
class GuiEntry
{
public:
    /* Handles appearance of the entry */
    /** 
     * @brief Rectangle shape representing the visual appearance of the entry. 
     */
    sf::RectangleShape shape;

    /* String returned when the entry is activated */
    /** 
     * @brief Message returned when the entry is activated. 
     */
    std::string message;

    /* Text displayed on the entry */
    /** 
     * @brief Text displayed on the entry.
     */
    sf::Text text;

    /**
     * @brief Constructs a new GuiEntry with specified message, shape, and text.
     *
     * @param message String returned when the entry is activated.
     * @param shape RectangleShape representing the entry's appearance.
     * @param text Text displayed on the entry.
     */
    GuiEntry(const std::string &message, sf::RectangleShape shape, sf::Text text)
    {
        this->message = message;
        this->shape = shape;
        this->text = text;
    }

    /**
     * @brief Default constructor for GuiEntry.
     */
    GuiEntry() {}
};


#endif