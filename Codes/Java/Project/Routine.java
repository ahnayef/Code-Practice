import java.util.List;
import javax.swing.*;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class Routine extends JFrame {

    private Map<String, List<Subject>> weeklyRoutine = new HashMap<>();

    private void loadRoutineData() {
        weeklyRoutine.put("sunday", Arrays.asList(
                new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin", "8:30 - 9:55", "R-412",
                        "STA-05422101", false),
                new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "10:00 - 11:25", "R-214", "CSE-06132115",
                        false),
                new Subject("Algorithm Design & Analysis", "Muthmainna Mou", "11:30 - 12:55", "R-412", "CSE-06132113",
                        false)));

        weeklyRoutine.put("monday", Arrays.asList(
                new Subject("Algorithm Design & Analysis Lab", "Muthmainna Mou", "8:30 - 11:25", "R-309",
                        "CSE-06132114", true),
                new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker", "11:30 - 12:55", "R-412",
                        "CSE-06132111", false),
                new Subject("Principles of Accounting", "Mr. Nasir Uddin", "1:00 - 2:25", "R-312", "BUS-04112101",
                        false)));

        weeklyRoutine.put("tuesday", Arrays.asList(
                new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker", "10:00 - 11:25", "R-412",
                        "CSE-06132111", false),
                new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "11:30 - 12:55", "R-309", "CSE-06132115",
                        false),
                new Subject("Algorithm Design & Analysis", "Muthmainna Mou", "1:00 - 2:25", "R-312", "CSE-06132113",
                        false)));

        weeklyRoutine.put("wednesday", Arrays.asList(
                new Subject("Digital Logic Design Lab", "K. M. Asif-uz-zaman", "8:30 - 11:25", "R-309", "CSE-06132116",
                        true),
                new Subject("Principles of Accounting", "Mr. Nasir Uddin", "1:00 - 2:25", "R-412", "BUS-04112101",
                        false)));

        weeklyRoutine.put("thursday", Arrays.asList(
                new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin", "8:30 - 9:55", "R-412",
                        "STA-05422101", false),
                new Subject("Object Oriented Programming Language Lab", "Mr. Pranta Sarker", "10:00 - 12:55", "R-309",
                        "CSE-06132112", true)));
    }

    class Subject {
        String name;
        String teacher;
        String time;
        String roomNo;
        String courseCode;
        Boolean lab;

        public Subject(String name, String teacher, String time, String roomNo, String courseCode, Boolean lab) {
            this.name = name;
            this.teacher = teacher;
            this.time = time;
            this.roomNo = roomNo;
            this.courseCode = courseCode;
            this.lab = lab;
        }
    }

    CardLayout cardLayout = new CardLayout();
    JPanel cardPanel = new JPanel(cardLayout);

    Color backgroundColor = new Color(28, 28, 28);
    Color textColor = new Color(253, 253, 253);
    Color grayTextColor = new Color(200, 200, 200);
    Color primary = new Color(0, 255, 127);

    Date date = new Date();

    public Routine() {
        loadRoutineData();
        setTitle("Academic Schedule Viewer");
        setSize(400, 620);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        // ----------------------------------------------
        // Home page :: Frame 1
        JPanel homePage = new JPanel();
        homePage.setBackground(backgroundColor);
        JButton viewRoutine = new JButton("View Routine");
        JButton viewCourse = new JButton("View Courses");
        JButton contactCR = new JButton("Contact CR");

        viewRoutine.setBackground(primary);
        viewCourse.setBackground(primary);
        contactCR.setBackground(primary);

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

        // ------------------------------------------------
        // Routine page :: Frame 2

        String today = new SimpleDateFormat("EEEE").format(date).toLowerCase();
        List<Subject> todaySubjects = weeklyRoutine.getOrDefault(today, new ArrayList<>());

        JPanel routinePage = new JPanel();
        JPanel buttonPanel = new JPanel();
        JPanel headingPanel = new JPanel();
        JPanel routinePanel = new JPanel();

        routinePage.setLayout(new BoxLayout(routinePage, BoxLayout.Y_AXIS));
        buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.X_AXIS));
        headingPanel.setLayout(new BoxLayout(headingPanel, BoxLayout.Y_AXIS));
        // routinePanel.setLayout(new GridLayout(todaySubjects.size(), 1));
        routinePanel.setLayout(new BoxLayout(routinePanel, BoxLayout.Y_AXIS));

        routinePage.setBackground(backgroundColor);
        routinePanel.setBackground(backgroundColor);
        headingPanel.setBackground(backgroundColor);

        routinePage.add(buttonPanel);
        routinePage.add(headingPanel);
        routinePage.add(routinePanel);

        buttonPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
        headingPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
        routinePanel.setAlignmentX(Component.CENTER_ALIGNMENT);

        JButton backHome = new JButton("🏠");
        backHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
        backHome.setBackground(primary);
        buttonPanel.add(backHome);

        JLabel currentDay = new JLabel(new SimpleDateFormat("EEEE").format(date));
        JLabel currentDate = new JLabel(new SimpleDateFormat("MMM dd, yyyy").format(date));

        currentDay.setForeground(textColor);
        currentDate.setForeground(grayTextColor);
        currentDay.setAlignmentX(Component.CENTER_ALIGNMENT);
        currentDate.setAlignmentX(Component.CENTER_ALIGNMENT);

        headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        headingPanel.add(currentDay);
        headingPanel.add(currentDate);
        headingPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        for (Subject subject : todaySubjects) {

            JPanel routineBox = new JPanel();
            JLabel subjectLabel = new JLabel(subject.name);
            JLabel courseCodeLabel = new JLabel(subject.courseCode);
            JLabel teacheLabel = new JLabel(subject.teacher);
            JLabel timeLabel = new JLabel(subject.time);
            JLabel roomLabel = new JLabel(subject.roomNo);

            routineBox.setLayout(new BoxLayout(routineBox, BoxLayout.Y_AXIS));
            routineBox.setBackground(backgroundColor);
            routineBox.setForeground(textColor);
            routineBox.setAlignmentX(Component.CENTER_ALIGNMENT);
            routineBox.setAlignmentY(Component.CENTER_ALIGNMENT);
            routineBox.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(primary, 1), 
                BorderFactory.createEmptyBorder(10, 10, 10, 10) 
            ));

            subjectLabel.setForeground(textColor);
            courseCodeLabel.setForeground(grayTextColor);
            teacheLabel.setForeground(textColor);
            timeLabel.setForeground(textColor);
            roomLabel.setForeground(textColor);

            subjectLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
            courseCodeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
            teacheLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
            timeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
            roomLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

            subjectLabel.setAlignmentY(Component.CENTER_ALIGNMENT);
            courseCodeLabel.setAlignmentY(Component.CENTER_ALIGNMENT);
            teacheLabel.setAlignmentY(Component.CENTER_ALIGNMENT);
            timeLabel.setAlignmentY(Component.CENTER_ALIGNMENT);
            roomLabel.setAlignmentY(Component.CENTER_ALIGNMENT);

            routineBox.setForeground(textColor);
            routineBox.add(subjectLabel);
            routineBox.add(courseCodeLabel);
            routineBox.add(teacheLabel);
            routineBox.add(timeLabel);
            routineBox.add(roomLabel);

            routinePanel.add(Box.createRigidArea(new Dimension(0, 20)));
            routinePanel.add(routineBox);
        }

        // ------------------------------------------------------
        // Handle button clicks
        viewRoutine.addActionListener(e -> cardLayout.show(cardPanel, "Routine"));
        viewCourse.addActionListener(e -> cardLayout.show(cardPanel, "Course"));
        contactCR.addActionListener(e -> cardLayout.show(cardPanel, "CR"));

        // ------------------------------------------------------
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