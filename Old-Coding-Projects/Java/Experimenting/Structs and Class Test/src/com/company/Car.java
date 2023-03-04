package com.company;

public class Car {

    private String carModel;
    private String brand;
    private int carYear;
    private int mileage;

    public Car(String carModel, String brand, int carYear, int mileage) {
        this.carModel = carModel;
        this.brand = brand;
        this.carYear = carYear;
        this.mileage = mileage;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getCarYear() {
        return carYear;
    }

    public void setCarYear(int carYear) {
        this.carYear = carYear;
    }

    public int getMileage() {
        return mileage;
    }

    public void setMileage(int mileage) {
        this.mileage = mileage;
    }

}
