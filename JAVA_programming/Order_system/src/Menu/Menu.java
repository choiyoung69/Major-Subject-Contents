package Menu;

import javax.swing.*;

// 메뉴 클래스
public class Menu {
    private String name;
    private int basePrice;
    private ImageIcon image;

    public Menu(String name, int basePrice, ImageIcon image) {
        this.name = name;
        this.basePrice = basePrice;
        this.image = image;
    }

    public String getName() {
        return name;
    }
    public int getBasePrice() {
        return basePrice;
    }
    public ImageIcon getImage() {
        return image;
    }
    public int getTotalPrice() {
        return basePrice;
    }
}
