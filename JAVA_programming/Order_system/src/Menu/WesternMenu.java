package Menu;

import javax.swing.*;

public class WesternMenu extends Menu {
    private boolean cheese;

    public WesternMenu(String name, int basePrice, ImageIcon image) {
        super(name, basePrice, image);
        this.cheese = false;
    }

    public boolean isCheese() {
        return cheese;
    }

    public void setCheese(boolean cheese) {
        this.cheese = cheese;
    }
    public int getTotalPrice() {
        return getBasePrice() + (cheese ? 3000 : 0);
    }
}
