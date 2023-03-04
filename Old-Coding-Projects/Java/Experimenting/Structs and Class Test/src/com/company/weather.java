package com.company;

public class weather {

    private boolean isRaining;
    private boolean isCloudy;
    private boolean isSunny;
    private boolean isOverCast;
    private boolean isThunder;
    private int temperature;

    public weather(boolean isRaining, boolean isCloudy, boolean isSunny, boolean isOverCast, boolean isThunder, int temperature) {
        this.isRaining = isRaining;
        this.isCloudy = isCloudy;
        this.isSunny = isSunny;
        this.isOverCast = isOverCast;
        this.isThunder = isThunder;
        this.temperature = temperature;
    }

    public boolean isRaining() {
        return isRaining;
    }

    public void setRaining(boolean raining) {
        isRaining = raining;
    }

    public boolean isCloudy() {
        return isCloudy;
    }

    public void setCloudy(boolean cloudy) {
        isCloudy = cloudy;
    }

    public boolean isSunny() {
        return isSunny;
    }

    public void setSunny(boolean sunny) {
        this.isSunny = sunny;
    }

    public boolean isOverCast() {
        return isOverCast;
    }

    public void setOverCast(boolean overCast) {
        isOverCast = overCast;
    }

    public boolean isThunder() {
        return isThunder;
    }

    public void setThunder(boolean thunder) {
        isThunder = thunder;
    }

    public void setTemperature(int temperature) {
        if (temperature >= -90 && temperature < 140) {
            this.temperature = temperature;
        } else {
            System.out.println("Temperature is out of range");
        }
    }

    public int getTemperature() {
        return this.temperature;
    }
}
