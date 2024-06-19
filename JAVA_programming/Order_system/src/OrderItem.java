import Menu.ChineseMenu;
import Menu.KoreanMenu;
import Menu.WesternMenu;
import Menu.Menu;

public class OrderItem {
    private Menu menu;
    private int quantity;

    private int price;

    public OrderItem(Menu menu, int quantity) {
        this.menu = menu;
        this.quantity = quantity;
    }

    public Menu getMenu() {
        return menu;
    }

    public int getQuantity() {
        return quantity;
    }

    public int getTotalPrice() {
        price = menu.getTotalPrice() * quantity;
        return price;
    }
}

