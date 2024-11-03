#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceInterface.h"
#include "Resources.h"

/**
 * @class ResourceManager
 * @brief Manages access and consumption of various resources.
 *
 * The ResourceManager class provides methods to access, modify, and consume different resources.
 * It acts as an interface between client code and the Resources singleton, enforcing consumption limits.
 */
class ResourceManager : public ResourceInterface {
private:
    Resources* resources;  ///< Pointer to the singleton instance of Resources.

public:
    /**
     * @brief Constructs a new ResourceManager object.
     *
     * Initializes the ResourceManager by obtaining the singleton instance of Resources.
     */
    ResourceManager();

    /**
     * @brief Destroys the ResourceManager object.
     *
     * Does not delete the Resources instance since it's a singleton.
     */
    ~ResourceManager();

    /**
     * @brief Gets the current water resource level.
     * @return The amount of water available.
     */
    int getWater();

    /**
     * @brief Gets the current power resource level.
     * @return The amount of power available.
     */
    int getPower();

    /**
     * @brief Gets the current sewage resource level.
     * @return The amount of sewage available.
     */
    int getSewage();

    /**
     * @brief Gets the current material resource level.
     * @return The amount of materials available.
     */
    int getMaterial();

    /**
     * @brief Sets the water resource to a new value.
     * @param value The new water resource amount.
     *
     * Sets the water resource if the value is positive and greater than or equal to the current amount.
     */
    void setWater(int value);

    /**
     * @brief Sets the power resource to a new value.
     * @param value The new power resource amount.
     *
     * Sets the power resource if the value is positive and greater than or equal to the current amount.
     */
    void setPower(int value);

    /**
     * @brief Sets the sewage resource to a new value.
     * @param value The new sewage resource amount.
     *
     * Sets the sewage resource if the value is positive and greater than or equal to the current amount.
     */
    void setSewage(int value);

    /**
     * @brief Sets the material resource to a new value.
     * @param value The new material resource amount.
     *
     * Sets the material resource if the value is positive and greater than or equal to the current amount.
     */
    void setMaterial(int value);

    /**
     * @brief Consumes a specified amount of water resource.
     * @param value The amount of water to consume.
     * @return True if the consumption is successful; false otherwise.
     *
     * Allows consumption if the requested amount is less than 20% of the available water.
     */
    bool consumeWater(int value);

    /**
     * @brief Consumes a specified amount of power resource.
     * @param value The amount of power to consume.
     * @return True if the consumption is successful; false otherwise.
     *
     * Allows consumption if the requested amount is less than 40% of the available power.
     */
    bool consumePower(int value);

    /**
     * @brief Consumes a specified amount of sewage resource.
     * @param value The amount of sewage to consume.
     * @return True if the consumption is successful; false otherwise.
     *
     * Allows consumption if the requested amount is less than 60% of the available sewage.
     */
    bool consumeSewage(int value);

    /**
     * @brief Consumes a specified amount of material resource.
     * @param value The amount of material to consume.
     * @return True if the consumption is successful; false otherwise.
     *
     * Allows consumption if the requested amount is less than 80% of the available materials.
     */
    bool consumeMaterial(int value);
};

#endif // RESOURCEMANAGER_H
