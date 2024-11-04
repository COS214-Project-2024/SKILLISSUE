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
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  virtual int getWater() = 0;

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  virtual int getPower() = 0;

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  virtual int getSewage() = 0;

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  virtual int getWaste() = 0;

  /**
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  virtual int getWaterConsumption() = 0;

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  virtual int getPowerConsumption() = 0;

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  virtual int getSewageConsumption() = 0;

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  virtual int getWasteConsumption() = 0;

  /**
   * @brief Gets the amount of water resource.
   * @return The current water resource level.
   */
  virtual double getWaterUsage() = 0;

  /**
   * @brief Gets the amount of power resource.
   * @return The current power resource level.
   */
  virtual double getPowerUsage() = 0;

  /**
   * @brief Gets the amount of sewage resource.
   * @return The current sewage resource level.
   */
  virtual double getSewageUsage() = 0;

  /**
   * @brief Gets the amount of materials resource.
   * @return The current materials resource level.
   */
  virtual double getWasteUsage() = 0;


  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  virtual void setWater(int value) = 0;

  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  virtual void setPower(int value) = 0;

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  virtual void setSewage(int value) = 0;

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  virtual void setWaste(int value) = 0;

  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  virtual void setWaterConsumption(int value) = 0;
  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  virtual void setPowerConsumption(int value) = 0;

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  virtual void setSewageConsumption(int value) = 0;

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  virtual void setWasteConsumption(int value) = 0;

  /**
   * @brief Sets the amount of water resource.
   * @param value The new value for the water resource.
   */
  virtual void setWaterUsage(double value) = 0;

  /**
   * @brief Sets the amount of power resource.
   * @param value The new value for the power resource.
   */
  virtual void setPowerUsage(double value) = 0;

  /**
   * @brief Sets the amount of sewage resource.
   * @param value The new value for the sewage resource.
   */
  virtual void setSewageUsage(double value) = 0;

  /**
   * @brief Sets the amount of materials resource.
   * @param value The new value for the materials resource.
   */
  virtual void setWasteUsage(double value) = 0;

  /**
   * @brief Decreases water resource by a specified amount.
   * @param value The amount to decrease the water resource by.
   */
};

#endif
