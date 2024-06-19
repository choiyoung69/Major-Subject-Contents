package Menu;

import javax.swing.*;

public class ChineseMenu extends Menu {
    private int spiceLevel; // 0: 보통, 1: 향신료 조금, 2: 향신료 많이

    public ChineseMenu(String name, int basePrice, ImageIcon image) {
        super(name, basePrice, image);
        this.spiceLevel = 0;
    }

    public int getSpiceLevel() {
        return spiceLevel;
    }

    public void setSpiceLevel(int spiceLevel) {
        this.spiceLevel = spiceLevel;
    }

    public int getTotalPrice() {
        return getBasePrice() + (spiceLevel * 500);

    }
}

