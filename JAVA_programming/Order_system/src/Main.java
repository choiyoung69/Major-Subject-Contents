import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import Menu.ChineseMenu;
import Menu.KoreanMenu;
import Menu.WesternMenu;
import Menu.Menu;

public class Main extends JFrame {
    private User user;
    private JPanel menuPanel;
    private JPanel cartPanel;
    private JLabel totalPriceLabel;

    public Main() {
        user = new User("홍길동");

        setTitle("Delivery Service");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 700); // 전체 창 크기 조정

        JMenuBar menuBar = new JMenuBar();

        // 한식 메뉴
        JMenu koreanMenu = new JMenu("한식");
        JMenuItem koreanMenuItem = new JMenuItem("보기");
        koreanMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showKoreanMenu();
            }
        });
        koreanMenu.add(koreanMenuItem);

        // 중식 메뉴
        JMenu chineseMenu = new JMenu("중식");
        JMenuItem chineseMenuItem = new JMenuItem("보기");
        chineseMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showChineseMenu();
            }
        });
        chineseMenu.add(chineseMenuItem);

        // 양식 메뉴
        JMenu westernMenu = new JMenu("양식");
        JMenuItem westernMenuItem = new JMenuItem("보기");
        westernMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showWesternMenu();
            }
        });
        westernMenu.add(westernMenuItem);

        // 메뉴바에 메뉴 추가
        menuBar.add(koreanMenu);
        menuBar.add(chineseMenu);
        menuBar.add(westernMenu);

        setJMenuBar(menuBar);

        // 왼쪽 패널 - 메뉴 선택
        menuPanel = new JPanel(new GridLayout(0, 1));
        JScrollPane menuScrollPane = new JScrollPane(menuPanel);
        add(menuScrollPane, BorderLayout.CENTER);

        // 오른쪽 패널 - 장바구니
        cartPanel = new JPanel();
        cartPanel.setLayout(new BoxLayout(cartPanel, BoxLayout.Y_AXIS));
        JScrollPane cartScrollPane = new JScrollPane(cartPanel);
        add(cartScrollPane, BorderLayout.EAST);

        // 장바구니 패널 크기 설정
        Dimension cartPanelSize = new Dimension(getWidth() / 3, getHeight());
        cartScrollPane.setPreferredSize(cartPanelSize);

        // 아래 패널 - 총 가격 표시와 주문하기 버튼
        JPanel bottomPanel = new JPanel(new BorderLayout());
        totalPriceLabel = new JLabel("총 가격: 0원", JLabel.CENTER);
        bottomPanel.add(totalPriceLabel, BorderLayout.CENTER);

        JButton orderButton = new JButton("주문하기");
        orderButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(Main.this, "주문이 완료되었습니다.");
                user.clearCart(); // 장바구니 비우기
                updateCartPanel(); // 장바구니 패널 업데이트
                updateTotalPrice(); // 총 가격 업데이트
            }
        });
        bottomPanel.add(orderButton, BorderLayout.SOUTH);
        add(bottomPanel, BorderLayout.SOUTH);

        // 메뉴 추가
        addMenus();

        // 메인 프레임 보이기
        setVisible(true);
    }

    private void addMenus() {
        for (Menu menu : MenuStorage.koreanMenuList) {
            menuPanel.add(createMenuPanel(menu));
        }
    }

    private void showKoreanMenu() {
        menuPanel.removeAll();
        for (Menu menu : MenuStorage.koreanMenuList) {
            menuPanel.add(createMenuPanel(menu));
        }
        menuPanel.revalidate();
        menuPanel.repaint();
    }

    private void showChineseMenu() {
        menuPanel.removeAll();
        for (Menu menu : MenuStorage.chineseMenuList) {
            menuPanel.add(createMenuPanel(menu));
        }
        menuPanel.revalidate();
        menuPanel.repaint();
    }

    private void showWesternMenu() {
        menuPanel.removeAll();
        for (Menu menu : MenuStorage.westernMenuList) {
            menuPanel.add(createMenuPanel(menu));
        }
        menuPanel.revalidate();
        menuPanel.repaint();
    }

    private JPanel createMenuPanel(Menu menu) {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setPreferredSize(new Dimension(300, 100)); // 각 메뉴 패널 크기 고정
        panel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));

        JLabel label = new JLabel(menu.getName() + " - " + menu.getBasePrice() + "원", JLabel.CENTER);
        label.setIcon(resizeImageIcon(menu.getImage(), 200, 150)); // 이미지 크기 조정
        panel.add(label, BorderLayout.NORTH);

        JPanel optionsPanel = new JPanel(new FlowLayout());

        if (menu instanceof KoreanMenu) {
            String[] spiceOptions = {"안 매움", "보통", "매움"};
            JComboBox<String> spiceComboBox = new JComboBox<>(spiceOptions);
            optionsPanel.add(new JLabel("매움 정도:"));
            optionsPanel.add(spiceComboBox);
            spiceComboBox.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ((KoreanMenu) menu).setSpiceLevel(spiceComboBox.getSelectedIndex());
                    updateTotalPrice(); // 매움 정도 선택 시 총 가격 업데이트
                }
            });
        } else if (menu instanceof ChineseMenu) {
            String[] spiceOptions = {"보통", "향신료 조금", "향신료 많이"};
            JComboBox<String> spiceComboBox = new JComboBox<>(spiceOptions);
            optionsPanel.add(new JLabel("향신료 정도:"));
            optionsPanel.add(spiceComboBox);
            spiceComboBox.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ((ChineseMenu) menu).setSpiceLevel(spiceComboBox.getSelectedIndex());
                    updateTotalPrice(); // 향신료 정도 선택 시 총 가격 업데이트
                }
            });
        } else if (menu instanceof WesternMenu) {
            JCheckBox cheeseCheckBox = new JCheckBox("치즈 추가 (3000원)");
            optionsPanel.add(cheeseCheckBox);
            cheeseCheckBox.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ((WesternMenu) menu).setCheese(cheeseCheckBox.isSelected());
                    updateTotalPrice(); // 치즈 추가 선택 시 총 가격 업데이트
                }
            });
        }

        JButton addToCartButton = new JButton("장바구니에 추가");
        addToCartButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int quantity = 1; // 임시로 1개만 추가하는 것으로 설정
                OrderItem item = new OrderItem(menu, quantity);
                user.addToCart(item);
                updateCartPanel(); // 장바구니 업데이트
                updateTotalPrice(); // 총 가격 업데이트
                JOptionPane.showMessageDialog(Main.this, "장바구니에 추가되었습니다.");
            }
        });
        optionsPanel.add(addToCartButton);

        panel.add(optionsPanel, BorderLayout.CENTER);

        return panel;
    }

    private void updateCartPanel() {
        // 장바구니 패널을 맨 위에서부터 다시 그리기 위해 모든 컴포넌트를 제거
        cartPanel.removeAll();

        // 장바구니 패널에 BoxLayout 사용하여 수직으로 쌓이도록 설정
        cartPanel.setLayout(new BoxLayout(cartPanel, BoxLayout.Y_AXIS));

        for (OrderItem item : user.getCart()) {
            JPanel itemPanel = new JPanel(new BorderLayout()); // BorderLayout으로 설정하여 컴포넌트를 배치

            JLabel nameLabel = new JLabel(item.getMenu().getName(), JLabel.CENTER); // 메뉴 이름을 중앙 정렬로 표시
            JLabel priceLabel = new JLabel(item.getTotalPrice() + "원", JLabel.CENTER); // 메뉴 가격을 중앙 정렬로 표시

            JPanel labelPanel = new JPanel(); // 메뉴 이름과 가격을 담을 패널 생성
            labelPanel.setLayout(new BorderLayout());
            labelPanel.add(nameLabel, BorderLayout.WEST); // 이름을 왼쪽에 배치
            labelPanel.add(priceLabel, BorderLayout.EAST); // 가격을 오른쪽에 배치

            itemPanel.add(labelPanel, BorderLayout.CENTER); // labelPanel을 itemPanel의 중앙에 추가

            // itemPanel이 cartPanel을 가로로 전체적으로 채우도록 설정
            itemPanel.setAlignmentX(Component.LEFT_ALIGNMENT); // 왼쪽 정렬로 설정
            itemPanel.setMaximumSize(new Dimension(Integer.MAX_VALUE, itemPanel.getPreferredSize().height));

            cartPanel.add(itemPanel); // cartPanel에 itemPanel을 추가
        }

        // 장바구니 패널을 다시 그리고 재배치
        cartPanel.revalidate();
        cartPanel.repaint();
    }







    private void updateTotalPrice() {
        int totalPrice = user.getTotalCartPrice();
        totalPriceLabel.setText("총 가격: " + totalPrice + "원");
    }

    private ImageIcon resizeImageIcon(ImageIcon icon, int width, int height) {
        Image img = icon.getImage();
        Image resizedImg = img.getScaledInstance(width, height, Image.SCALE_SMOOTH);
        return new ImageIcon(resizedImg);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main();
            }
        });
    }
}

