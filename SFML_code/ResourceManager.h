#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceInterface.h"
#include "Resources.h"

/**
 * @class ResourceManager
 * @brief Manages access to and modification of various resources.
 *
 * The ResourceManager class provides methods to access and modify resources
 * such as water, power, sewage, and material. It implements the ResourceInterface
 * and utilizes the Resources class internally to manage resource data.
 *
 * This class ensures that resource usage adheres to specified constraints.
 * For example, it restricts the amount of resource that can be consumed in a single operation.
 */
class ResourceManager : public ResourceInterface, private Resources {
public:
  /**
   * @brief Constructs a new ResourceManager object.
   */
  ResourceManager();

  /**
   * @brief Destructs the ResourceManager object.
   */
  ~ResourceManager();

  /**
   * @brief Retrieves the current amount of water resource.
   * @return The amount of water available.
   */
  int getWater();

  /**
   * @brief Retrieves the current amount of power resource.
   * @return The amount of power available.
   */
  int getPower();

  /**
   * @brief Retrieves the current amount of sewage resource.
   * @return The amount of sewage available.
   */
  int getSewage();

  /**
   * @brief Retrieves the current amount of material resource.
   * @return The amount of material available.
   */
  int getMaterial();

  /**
   * @brief Sets the water resource amount to a new value.
   * @param value The new water amount to set.
   *
   * @note The new value must be positive and greater than or equal to the current water amount.
   *       If the conditions are not met, the water amount remains unchanged.
   */
  void setWater(int value);

  /**
   * @brief Sets the power resource amount to a new value.
   * @param value The new power amount to set.
   *
   * @note The new value must be positive and greater than or equal to the current power amount.
   *       If the conditions are not met, the power amount remains unchanged.
   */
  void setPower(int value);

  /**
   * @brief Sets the sewage resource amount to a new value.
   * @param value The new sewage amount to set.
   *
   * @note The new value must be positive and greater than or equal to the current sewage amount.
   *       If the conditions are not met, the sewage amount remains unchanged.
   */
  void setSewage(int value);

  /**
   * @brief Sets the material resource amount to a new value.
   * @param value The new material amount to set.
   *
   * @note The new value must be positive and greater than or equal to the current material amount.
   *       If the conditions are not met, the material amount remains unchanged.
   */
  void setMaterial(int value);

  /**
   * @brief Consumes a specified amount of water resource.
   * @param value The amount of water to consume.
   * @return True if the water consumption was successful, false otherwise.
   *
   * @details The amount to consume must be less than 20% of the available water.
   *          If the condition is not met, the water amount remains unchanged and the method returns false.
   */
  bool useWater(int value);

  /**
   * @brief Consumes a specified amount of power resource.
   * @param value The amount of power to consume.
   * @return True if the power consumption was successful, false otherwise.
   *
   * @details The amount to consume must be less than 40% of the available power.
   *          If the condition is not met, the power amount remains unchanged and the method returns false.
   */
  bool usePower(int value);

  /**
   * @brief Consumes a specified amount of sewage resource.
   * @param value The amount of sewage to consume.
   * @return True if the sewage consumption was successful, false otherwise.
   *
   * @details The amount to consume must be less than 60% of the available sewage.
   *          If the condition is not met, the sewage amount remains unchanged and the method returns false.
   */
  bool useSewage(int value);

  /**
   * @brief Consumes a specified amount of material resource.
   * @param value The amount of material to consume.
   * @return True if the material consumption was successful, false otherwise.
   *
   * @details The amount to consume must be less than 80% of the available material.
   *          If the condition is not met, the material amount remains unchanged and the method returns false.
   */
  bool useMaterial(int value);
};

#endif
