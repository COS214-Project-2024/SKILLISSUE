#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>
#include <string>
#include "GuiEntry.h"
#include "GuiStyle.h"

/**
 * @class Gui
 * @brief Represents a graphical user interface (GUI) element for menus and interactive lists.
 *
 * The Gui class provides a flexible GUI system for displaying a menu of entries, either
 * horizontally or vertically. Each entry can be customized with text and styling, and
 * users can interact with entries to perform various actions.
 */
class Gui : public sf::Transformable, public sf::Drawable
{
private:
    /* If true the menu entries will be horizontally, not vertically, adjacent */
    /** @brief Determines if the entries are displayed horizontally. */
    bool horizontal;

    /** @brief Styling information for the GUI, including colors and fonts. */
    GuiStyle style;

    /** @brief Dimensions of the GUI background shape. */
    sf::Vector2f dimensions;

    /** @brief Padding between GUI entries. */
    int padding;

public:

    /** @brief List of entries contained within the GUI. */
    std::vector<GuiEntry> entries;

    /** @brief Visibility flag for the GUI. If true, the GUI is visible. */
    bool visible;

    /* Constructor */
    /**
     * @brief Constructs a new Gui instance.
     *
     * Initializes the GUI with specified dimensions, padding, alignment, style, and entries.
     * @param dimensions Size of the GUI background.
     * @param padding Spacing between entries.
     * @param horizontal If true, entries are arranged horizontally; otherwise, vertically.
     * @param style Style settings for the GUI appearance.
     * @param entries List of entry name and message pairs.
     */
    Gui(sf::Vector2f dimensions, int padding, bool horizontal,
        GuiStyle &style, std::vector<std::pair<std::string, std::string> > entries)
    {
        visible = false;
        this->horizontal = horizontal;
        this->style = style;
        this->dimensions = dimensions;
        this->padding = padding;

        /* Construct the background shape */
        sf::RectangleShape shape;
        shape.setSize(dimensions);
        shape.setFillColor(style.bodyCol);
        shape.setOutlineThickness(-style.borderSize);
        shape.setOutlineColor(style.borderCol);

        /* Construct each gui entry */
        for (auto entry : entries)
        {
            /* Construct the text */
            sf::Text text;
            text.setString(entry.first);
            text.setFont(*style.font);
            text.setFillColor(style.textCol);
            text.setCharacterSize(dimensions.y - style.borderSize - padding);

            this->entries.push_back(GuiEntry(entry.second, shape, text));
        }
    }

    /**
     * @brief Retrieves the dimensions of the GUI.
     * @return sf::Vector2f Dimensions of the GUI.
     */
    sf::Vector2f getSize();

    /**
     * @brief Gets the index of the entry that the mouse is hovering over.
     *
     * Returns -1 if the mouse is outside of the GUI.
     * @param mousePos The current position of the mouse.
     * @return int Index of the hovered entry, or -1 if none.
     */
    int getEntry(const sf::Vector2f mousePos);

    /* Change the text of an entry. */
    /**
     * @brief Sets the text of a specified entry.
     * @param entry Index of the entry to modify.
     * @param text New text for the entry.
     */
    void setEntryText(int entry, std::string text);

    /* Change the entry dimensions. */
    /**
     * @brief Updates the dimensions of the GUI.
     * @param dimensions New dimensions for the GUI background.
     */
    void setDimensions(sf::Vector2f dimensions);

    /* Draw the menu. */
    /**
     * @brief Draws the GUI to the specified render target.
     * @param target Render target to draw the GUI on.
     * @param states Render states to apply during drawing.
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    /**
     * @brief Makes the GUI visible on the screen.
     */
    void show();

    /**
     * @brief Hides the GUI from the screen.
     */
    void hide();

    /* Highlights an entry of the menu. */
    /**
     * @brief Highlights a specified entry in the GUI.
     * @param entry Index of the entry to highlight.
     */
    void highlight(const int entry);

    /* Return the message bound to the entry. */
    /**
     * @brief Activates the action bound to a specified entry.
     * @param entry Index of the entry to activate.
     * @return std::string Message associated with the activated entry.
     */
    std::string activate(const int entry);

    /**
     * @brief Activates the action bound to the entry at a specified mouse position.
     * @param mousePos Position of the mouse.
     * @return std::string Message associated with the activated entry.
     */
    std::string activate(const sf::Vector2f mousePos);
};

#endif /* GUI_HPP */
