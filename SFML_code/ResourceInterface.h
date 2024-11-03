#ifndef RESOURCEINTERFACE_H
#define RESOURCEINTERFACE_H

/**
 * @class ResourceInterface
 * @brief An abstract interface for resource management operations.
 *
 * The ResourceInterface class defines a set of pure virtual methods
 * that must be implemented by any class responsible for managing resources
 * such as water, power, sewage, and material. This interface ensures a
 * consistent API for resource management across different implementations.
 */
class ResourceInterface {

public:
    /**
     * @brief Retrieves the current amount of water resource.
     * @return The amount of water available.
     */
    virtual int getWater() = 0;

    /**
     * @brief Retrieves the current amount of power resource.
     * @return The amount of power available.
     */
    virtual int getPower() = 0;

    /**
     * @brief Retrieves the current amount of sewage resource.
     * @return The amount of sewage available.
     */
    virtual int getSewage() = 0;

    /**
     * @brief Retrieves the current amount of material resource.
     * @return The amount of material available.
     */
    virtual int getMaterial() = 0;

    /**
     * @brief Sets the water resource amount to a new value.
     * @param value The new water amount to set.
     */
    virtual void setWater(int value) = 0;

    /**
     * @brief Sets the power resource amount to a new value.
     * @param value The new power amount to set.
     */
    virtual void setPower(int value) = 0;

    /**
     * @brief Sets the sewage resource amount to a new value.
     * @param value The new sewage amount to set.
     */
    virtual void setSewage(int value) = 0;

    /**
     * @brief Sets the material resource amount to a new value.
     * @param value The new material amount to set.
     */
    virtual void setMaterial(int value) = 0;

    /**
     * @brief Consumes a specified amount of water resource.
     * @param value The amount of water to consume.
     * @return True if the water consumption was successful, false otherwise.
     */
    virtual bool useWater(int value) = 0;

    /**
     * @brief Consumes a specified amount of power resource.
     * @param value The amount of power to consume.
     * @return True if the power consumption was successful, false otherwise.
     */
    virtual bool usePower(int value) = 0;

    /**
     * @brief Consumes a specified amount of sewage resource.
     * @param value The amount of sewage to consume.
     * @return True if the sewage consumption was successful, false otherwise.
     */
    virtual bool useSewage(int value) = 0;

    /**
     * @brief Consumes a specified amount of material resource.
     * @param value The amount of material to consume.
     * @return True if the material consumption was successful, false otherwise.
     */
    virtual bool useMaterial(int value) = 0;
};

#endif
