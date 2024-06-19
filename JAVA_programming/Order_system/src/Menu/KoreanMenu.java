package Menu;

import javax.swing.*;

public class KoreanMenu extends Menu {
    private int spiceLevel; // 0: 안 매움, 1: 보통, 2: 매움

    public KoreanMenu(String name, int basePrice, ImageIcon image) {
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

