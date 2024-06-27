import javax.swing.*;
import java.awt.*;
import java.util.Date;

public class Routine extends JFrame {
    CardLayout cardLayout = new CardLayout();
    JPanel cardPanel = new JPanel(cardLayout);

    public Routine() {
        setTitle("Academic Schedule Viewer");
        setSize(578, 1080);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // Home page :: Frame 1
        JPanel homePage = new JPanel();
        JButton viewRoutine = new JButton("View Routine");
        JButton viewCourse = new JButton("View Courses");
        JButton contactCR = new JButton("Contact CR");
        homePage.setLayout(new BoxLayout(homePage, BoxLayout.Y_AXIS));
        homePage.add(Box.createVerticalGlue());
        viewRoutine.setAlignmentX(Component.CENTER_ALIGNMENT);
        viewCourse.setAlignmentX(Component.CENTER_ALIGNMENT);
        contactCR.setAlignmentX(Component.CENTER_ALIGNMENT);
        homePage.add(viewRoutine);
        homePage.add(Box.createRigidArea(new Dimension(0, 20)));
        homePage.add(viewCourse);
        homePage.add(Box.createRigidArea(new Dimension(0, 20)));
        homePage.add(contactCR);
        homePage.add(Box.createVerticalGlue());

        // Routine page :: Frame 2
        JPanel routinePage = new JPanel();
        JPanel buttonPanel = new JPanel();
        JPanel headingPanel = new JPanel();
        JPanel routinePanel = new JPanel();

        routinePage.setLayout(new BoxLayout(routinePage, BoxLayout.Y_AXIS)); 
        buttonPanel.setLayout(new BorderLayout());
        headingPanel.setLayout(new BoxLayout(headingPanel, BoxLayout.Y_AXIS));
        routinePanel.setLayout(new GridLayout(1, 3));

        routinePage.add(buttonPanel);
        routinePage.add(headingPanel);
        routinePage.add(routinePanel);

        JButton backHome = new JButton("⬅️");
        backHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
        
        JLabel currentDay = new JLabel(new Date().toString());
        JLabel currentDate = new JLabel(new Date().toString());
        currentDay.setAlignmentX(Component.CENTER_ALIGNMENT);
        currentDate.setAlignmentX(Component.CENTER_ALIGNMENT);
        buttonPanel.add(backHome, "West");
        headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        headingPanel.add(currentDay);
        headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        headingPanel.add(currentDate);



    
        // JButton backHome = new JButton("⬅️");
        // backHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
        // JLabel currentDay = new JLabel(new Date().toString());
        // JLabel currentDate = new JLabel(new Date().toString());
        // // routinePage.setLayout(new BoxLayout(routinePage, BoxLayout.Y_AXIS));
        // backHome.setAlignmentX(Component.LEFT_ALIGNMENT);
        // currentDay.setAlignmentX(Component.CENTER_ALIGNMENT);
        // currentDate.setAlignmentX(Component.CENTER_ALIGNMENT);
        // routinePage.add(Box.createRigidArea(new Dimension(0, 20)));
        // routinePage.add(currentDay);
        // routinePage.add(Box.createRigidArea(new Dimension(0, 20)));
        // routinePage.add(currentDate);
        // backHome.setBounds(1, 1, 100, 50);




        // Handle button clicks
        viewRoutine.addActionListener(e -> cardLayout.show(cardPanel, "Routine"));
        viewCourse.addActionListener(e -> cardLayout.show(cardPanel, "Course"));
        contactCR.addActionListener(e -> cardLayout.show(cardPanel, "CR"));

        // Add pages to cardPanel
        cardPanel.add(homePage, "Home");
        cardPanel.add(routinePage, "Routine");
        add(cardPanel);

    }

}

class Main {
    public static void main(String[] args) {
        new Routine().setVisible(true);
    }
}