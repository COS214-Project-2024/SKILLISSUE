#ifndef RESOURCES_H
#define RESOURCES_H

/**
 * @class ResourceManager
 * @brief Manages various resources in a system, such as water, power, sewage,
 * and materials.
 *
 * The ResourceManager class is a singleton that provides methods to access and
 * modify different resources. It inherits from the Subject class.
 */
class Resources {

private:
  int waterProduced = 0;                 ///< The amount of water resource.
  int powerProduced = 0;                 ///< The amount of power resource.
  int sewageProduced = 0;                ///< The amount of sewage resource.
  int wasteProduced = 0;                 ///< The amount of materials resource.
  int waterConsumption = 0;              ///< The amount of water resource.
  int powerConsumption = 0;              ///< The amount of power resource.
  int sewageConsumption = 0;             ///< The amount of sewage resource.
  int wasteConsumption = 0;              ///< The amount of materials resource.
  double waterUsage = 0;
  double powerUsage = 0;
  double sewageUsage = 0;
  double wasteUsage = 0;

protected:
  /**
   * @brief Protected constructor to ensure only one instance of Resources
   * is created.
   */
  Resources();

  /**
   * @brief Copy constructor (protected and not implemented to prevent copying).
   */
  Resources(const Resources &) {};

  /**
   * @brief Assignment operator (protected and not implemented to prevent
   * copying).
   */
  Resources &operator=(const Resources &) {};

  /**
   * @brief Destructor.
   */
  virtual ~Resources() {};

public:
  /**
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  int getWater();

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  int getPower();

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  int getSewage();

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  int getWaste();

  /**
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  int getWaterConsumption();

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  int getPowerConsumption();

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  int getSewageConsumption();

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  int getWasteConsumption();

  /**
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  double getWaterUsage();

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  double getPowerUsage();

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  double getSewageUsage();

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  double getWasteUsage();


  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  void setWater(int value);

  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  void setPower(int value);

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  void setSewage(int value);

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  void setWaste(int value);

  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  void setWaterConsumption(int value);

  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  void setPowerConsumption(int value);

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  void setSewageConsumption(int value);

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  void setWasteConsumption(int value);

  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  void setWaterUsage(double value);

  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  void setPowerUsage(double value);

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  void setSewageUsage(double value);

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  void setWasteUsage(double value);

  /**
   * @brief Decreases water resource by a specified amount.
   * @param value The amount to decrease the water resource by.
   */
  void consumeWater(int value);

  /**
   * @brief Decreases power resource by a specified amount.
   * @param value The amount to decrease the power resource by.
   */
  void consumePower(int value);

  /**
   * @brief Decreases sewage resource by a specified amount.
   * @param value The amount to decrease the sewage resource by.
   */
  void consumeSewage(int value);

  /**
   * @brief Decreases materials resource by a specified amount.
   * @param value The amount to decrease the materials resource by.
   */
  void consumeWaste(int value);

  /**
   * @brief Gets the singleton instance of Resources.
   * @return A reference to the singleton Resources instance.
   */
  static Resources &getResourcesInstance();
};

#endif