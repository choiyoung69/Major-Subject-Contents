import Menu.ChineseMenu;
import Menu.KoreanMenu;
import Menu.WesternMenu;
import Menu.Menu;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class MenuStorage {
    static List<Menu> koreanMenuList = new ArrayList<>();
    static List<Menu> chineseMenuList = new ArrayList<>();
    static List<Menu> westernMenuList = new ArrayList<>();

    static {
        koreanMenuList.add(new KoreanMenu("김치찌개", 8000, scaleImageIcon("김치찌개.png", 100, 100)));
        koreanMenuList.add(new KoreanMenu("비빔밥", 9000, scaleImageIcon("비빔밥.jpg", 100, 100)));
        koreanMenuList.add(new KoreanMenu("불고기", 15000, scaleImageIcon("불고기.jpg", 100, 100)));

        chineseMenuList.add(new ChineseMenu("짜장면", 6000, scaleImageIcon("짜장면.jpg", 100, 100)));
        chineseMenuList.add(new ChineseMenu("탕수육", 18000, scaleImageIcon("탕수육.jpg", 100, 100)));
        chineseMenuList.add(new ChineseMenu("마파두부", 12000, scaleImageIcon("마파두부.png", 100, 100)));

        westernMenuList.add(new WesternMenu("파스타", 13000, scaleImageIcon("파스타.jpg", 100, 100)));
        westernMenuList.add(new WesternMenu("피자", 20000, scaleImageIcon("피자.jpg", 100, 100)));
        westernMenuList.add(new WesternMenu("스테이크", 30000, scaleImageIcon("스테이크.jpg", 100, 100)));
    }

    // 이미지 크기 조정 메서드
    private static ImageIcon scaleImageIcon(String imagePath, int width, int height) {
        ImageIcon originalIcon = new ImageIcon(imagePath);
        Image scaledImage = originalIcon.getImage().getScaledInstance(width, height, Image.SCALE_SMOOTH);
        return new ImageIcon(scaledImage);
    }

    public List<Menu> getKoreanMenus() {
        return koreanMenuList;
    }

    public List<Menu> getChineseMenus() {
        return chineseMenuList;
    }

    public List<Menu> getWesternMenus() {
        return westernMenuList;
    }
}

