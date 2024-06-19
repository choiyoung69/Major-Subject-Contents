import java.util.ArrayList;
import java.util.List;

public class User {
    private String name;
    private List<OrderItem> cart;

    public User(String name) {
        this.name = name;
        this.cart = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public List<OrderItem> getCart() {
        return cart;
    }

    public void addToCart(OrderItem item) {
        cart.add(item);
    }

    public int getTotalCartPrice() {
        int total = 0;
        for (OrderItem item : cart) {
            total += item.getTotalPrice();
        }
        return total;
    }

    public void clearCart() {
        cart.clear();
    }
}
