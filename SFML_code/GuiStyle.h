#ifndef GUISTYLE_H
#define GUISTYLE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <utility>
#include <string>

/**
 * @class GuiStyle
 * @brief Represents the visual styling for GUI elements.
 *
 * A GuiStyle encapsulates colors, fonts, and border properties used for rendering
 * graphical user interface components, such as buttons or menus. It allows for
 * easy customization of the appearance of GUI elements in a consistent manner.
 */
class GuiStyle
{
public:
    /** Color of the body of the GUI element. */
    sf::Color bodyCol;

    /** Color of the body when highlighted. */
    sf::Color bodyHighlightCol;

    /** Color of the border of the GUI element. */
    sf::Color borderCol;

    /** Color of the border when highlighted. */
    sf::Color borderHighlightCol;

    /** Color of the text displayed on the GUI element. */
    sf::Color textCol;

    /** Color of the text when highlighted. */
    sf::Color textHighlightCol;

    /** Pointer to the font used for the text. */
    sf::Font *font;

    /** Size of the border around the GUI element. */
    float borderSize;

    /**
     * @brief Constructs a new GuiStyle with specified visual properties.
     *
     * @param font Pointer to the font used for text rendering.
     * @param borderSize Size of the border.
     * @param bodyCol Color of the body.
     * @param borderCol Color of the border.
     * @param textCol Color of the text.
     * @param bodyHighlightCol Color of the body when highlighted.
     * @param borderHighlightCol Color of the border when highlighted.
     * @param textHighlightCol Color of the text when highlighted.
     */
    GuiStyle(sf::Font *font, float borderSize,
             sf::Color bodyCol, sf::Color borderCol, sf::Color textCol,
             sf::Color bodyHighlightCol, sf::Color borderHighlightCol, sf::Color textHighlightCol)
    {
        this->bodyCol = bodyCol;
        this->borderCol = borderCol;
        this->textCol = textCol;
        this->bodyHighlightCol = bodyHighlightCol;
        this->borderHighlightCol = borderHighlightCol;
        this->textHighlightCol = textHighlightCol;
        this->font = font;
        this->borderSize = borderSize;
    }

    /**
     * @brief Default constructor for GuiStyle.
     */
    GuiStyle() {}
};

#endif