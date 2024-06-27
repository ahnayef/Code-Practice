import java.util.List;
import javax.swing.*;
import java.awt.*;
import java.net.URI;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class Routine extends JFrame {

        class Course {
                String courseTitle;
                String instructor;

                public Course(String courseTitle, String instructor) {
                        this.courseTitle = courseTitle;
                        this.instructor = instructor;
                }
        }

        private List<Map<String, String>> courseList = Arrays.asList(
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Object Oriented Programming Language");
                                        put("Instructor", "Mr. Pranta Sarker");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Algorithm Design & Analysis");
                                        put("Instructor", "Muthmainna Mou");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Digital Logic Design");
                                        put("Instructor", "K. M. Asif-uz-zaman");
                                }
                        },
                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Basic Statistics and Probability");
                                        put("Instructor", "Mr. Mohammad Salah Uddin");
                                }
                        },

                        new HashMap<String, String>() {
                                {
                                        put("Course Title", "Principles of Accounting");
                                        put("Instructor", "Mr. Nasir Uddin");
                                }
                        });

        private Map<String, List<Subject>> weeklyRoutine = new HashMap<>();

        private void loadRoutineData() {
                weeklyRoutine.put("sunday", Arrays.asList(
                                new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin",
                                                "8:30 - 9:55", "R-412",
                                                "STA-05422101", false),
                                new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "10:00 - 11:25", "R-214",
                                                "CSE-06132115",
                                                false),
                                new Subject("Algorithm Design & Analysis", "Muthmainna Mou", "11:30 - 12:55", "R-412",
                                                "CSE-06132113",
                                                false)));

                weeklyRoutine.put("monday", Arrays.asList(
                                new Subject("Algorithm Design & Analysis Lab", "Muthmainna Mou", "8:30 - 11:25",
                                                "R-309",
                                                "CSE-06132114", true),
                                new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker",
                                                "11:30 - 12:55", "R-412",
                                                "CSE-06132111", false),
                                new Subject("Principles of Accounting", "Mr. Nasir Uddin", "1:00 - 2:25", "R-312",
                                                "BUS-04112101",
                                                false)));

                weeklyRoutine.put("tuesday", Arrays.asList(
                                new Subject("Object Oriented Programming Language", "Mr. Pranta Sarker",
                                                "10:00 - 11:25", "R-412",
                                                "CSE-06132111", false),
                                new Subject("Digital Logic Design", "K. M. Asif-uz-zaman", "11:30 - 12:55", "R-309",
                                                "CSE-06132115",
                                                false),
                                new Subject("Algorithm Design & Analysis", "Muthmainna Mou", "1:00 - 2:25", "R-312",
                                                "CSE-06132113",
                                                false)));

                weeklyRoutine.put("wednesday", Arrays.asList(
                                new Subject("Digital Logic Design Lab", "K. M. Asif-uz-zaman", "8:30 - 11:25", "R-309",
                                                "CSE-06132116",
                                                true),
                                new Subject("Principles of Accounting", "Mr. Nasir Uddin", "1:00 - 2:25", "R-412",
                                                "BUS-04112101",
                                                false)));

                weeklyRoutine.put("thursday", Arrays.asList(
                                new Subject("Basic Statistics and Probability", "Mr. Mohammad Salah Uddin",
                                                "8:30 - 9:55", "R-412",
                                                "STA-05422101", false),
                                new Subject("Object Oriented Programming Language Lab", "Mr. Pranta Sarker",
                                                "10:00 - 12:55", "R-309",
                                                "CSE-06132112", true)));
        }

        class Subject {
                String name;
                String teacher;
                String time;
                String roomNo;
                String courseCode;
                Boolean lab;

                public Subject(String name, String teacher, String time, String roomNo, String courseCode,
                                Boolean lab) {
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
                JButton exitButton = new JButton("Exit");

                viewRoutine.setBackground(primary);
                viewCourse.setBackground(primary);
                contactCR.setBackground(primary);
                exitButton.setBackground(Color.RED);

                homePage.setLayout(new BoxLayout(homePage, BoxLayout.Y_AXIS));
                homePage.add(Box.createVerticalGlue());
                viewRoutine.setAlignmentX(CENTER_ALIGNMENT);
                viewCourse.setAlignmentX(CENTER_ALIGNMENT);
                contactCR.setAlignmentX(CENTER_ALIGNMENT);
                exitButton.setAlignmentX(CENTER_ALIGNMENT);
                homePage.add(viewRoutine);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(viewCourse);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(contactCR);
                homePage.add(Box.createRigidArea(new Dimension(0, 20)));
                homePage.add(exitButton);
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
                routinePanel.setLayout(new BoxLayout(routinePanel, BoxLayout.Y_AXIS));

                routinePage.setBackground(backgroundColor);
                routinePanel.setBackground(backgroundColor);
                headingPanel.setBackground(backgroundColor);

                routinePage.add(buttonPanel);
                routinePage.add(headingPanel);
                routinePage.add(routinePanel);

                buttonPanel.setAlignmentX(CENTER_ALIGNMENT);
                headingPanel.setAlignmentX(CENTER_ALIGNMENT);
                routinePanel.setAlignmentX(CENTER_ALIGNMENT);

                JButton backHome = new JButton("🏠");
                backHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                backHome.setBackground(primary);
                buttonPanel.add(backHome);

                JLabel currentDay = new JLabel(new SimpleDateFormat("EEEE").format(date));
                JLabel currentDate = new JLabel(new SimpleDateFormat("MMM dd, yyyy").format(date));

                currentDay.setForeground(textColor);
                currentDate.setForeground(grayTextColor);
                currentDay.setAlignmentX(CENTER_ALIGNMENT);
                currentDate.setAlignmentX(CENTER_ALIGNMENT);

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
                        routineBox.setAlignmentX(CENTER_ALIGNMENT);
                        routineBox.setAlignmentY(CENTER_ALIGNMENT);
                        routineBox.setBorder(
                                        BorderFactory.createCompoundBorder(BorderFactory.createLineBorder(primary, 1),
                                                        BorderFactory.createEmptyBorder(10, 10, 10, 10)));

                        subjectLabel.setForeground(textColor);
                        courseCodeLabel.setForeground(grayTextColor);
                        teacheLabel.setForeground(textColor);
                        timeLabel.setForeground(textColor);
                        roomLabel.setForeground(textColor);

                        subjectLabel.setAlignmentX(CENTER_ALIGNMENT);
                        courseCodeLabel.setAlignmentX(CENTER_ALIGNMENT);
                        teacheLabel.setAlignmentX(CENTER_ALIGNMENT);
                        timeLabel.setAlignmentX(CENTER_ALIGNMENT);
                        roomLabel.setAlignmentX(CENTER_ALIGNMENT);

                        subjectLabel.setAlignmentY(CENTER_ALIGNMENT);
                        courseCodeLabel.setAlignmentY(CENTER_ALIGNMENT);
                        teacheLabel.setAlignmentY(CENTER_ALIGNMENT);
                        timeLabel.setAlignmentY(CENTER_ALIGNMENT);
                        roomLabel.setAlignmentY(CENTER_ALIGNMENT);

                        routineBox.setForeground(textColor);
                        routineBox.add(subjectLabel);
                        routineBox.add(courseCodeLabel);
                        routineBox.add(teacheLabel);
                        routineBox.add(timeLabel);
                        routineBox.add(roomLabel);

                        routinePanel.add(Box.createRigidArea(new Dimension(0, 20)));
                        routinePanel.add(routineBox);
                }

                // ------------------------------------------------
                // Course List page :: Frame 3

                JPanel courseListPage = new JPanel();

                JButton coursebackHome = new JButton("🏠");
                coursebackHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                coursebackHome.setBackground(primary);

                JLabel courseListLabel = new JLabel("Course List");

                courseListPage.setLayout(new BoxLayout(courseListPage, BoxLayout.Y_AXIS));
                courseListPage.setAlignmentX(CENTER_ALIGNMENT);

                coursebackHome.setAlignmentX(CENTER_ALIGNMENT);
                courseListLabel.setAlignmentX(CENTER_ALIGNMENT);

                courseListPage.setBackground(backgroundColor);
                courseListLabel.setForeground(textColor);

                courseListPage.add(coursebackHome);
                courseListPage.add(Box.createRigidArea(new Dimension(0, 20)));
                courseListPage.add(courseListLabel);
                courseListPage.add(Box.createRigidArea(new Dimension(0, 20)));

                JPanel courseListPanel = new JPanel();
                courseListPanel.setLayout(new BoxLayout(courseListPanel, BoxLayout.Y_AXIS));

                courseListPanel.setBackground(backgroundColor);
                courseListPanel.setForeground(textColor);

                String[] columnNames = { "Course Title", "Instructor" };
                Object[][] data = courseList.stream()
                                .map(course -> new Object[] { course.get("Course Title"), course.get("Instructor") })
                                .toArray(Object[][]::new);
                JTable table = new JTable(data, columnNames);
                table.setBackground(backgroundColor);
                table.setForeground(textColor);
                courseListPanel.add(table.getTableHeader());
                courseListPanel.add(table);
                courseListPage.add(courseListPanel);

                // ------------------------------------------------
                // CR page :: Frame 4

                JPanel crPage = new JPanel();
                JPanel infoPanel = new JPanel();

                JLabel crLabel = new JLabel("Contact CR");
                JButton crbackHome = new JButton("🏠");
                crbackHome.addActionListener(e -> cardLayout.show(cardPanel, "Home"));
                crbackHome.setBackground(primary);

                JLabel crName = new JLabel("Hrithik Dev Nath");
                JLabel tel = new JLabel("Phone: 01905078029");
                JLabel email = new JLabel("Email: hrithikdevnath0924@gmail.com");
                JLabel whatsapp = new JLabel("Whatsapp: 01905078029");

                crPage.setLayout(new BoxLayout(crPage, BoxLayout.Y_AXIS));
                infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));

                crbackHome.setAlignmentX(CENTER_ALIGNMENT);
                crLabel.setAlignmentX(CENTER_ALIGNMENT);
                crPage.setAlignmentX(CENTER_ALIGNMENT);
                infoPanel.setAlignmentX(CENTER_ALIGNMENT);
                crName.setAlignmentX(CENTER_ALIGNMENT);
                email.setAlignmentX(CENTER_ALIGNMENT);
                whatsapp.setAlignmentX(CENTER_ALIGNMENT);

                crPage.setBackground(backgroundColor);
                infoPanel.setBackground(backgroundColor);
                crLabel.setForeground(textColor);
                crPage.setForeground(textColor);
                infoPanel.setForeground(textColor);
                crName.setForeground(textColor);
                tel.setForeground(textColor);
                email.setForeground(textColor);
                whatsapp.setForeground(textColor);

                infoPanel.setBorder(
                                BorderFactory.createCompoundBorder(BorderFactory.createLineBorder(primary, 1),
                                                BorderFactory.createEmptyBorder(10, 10, 10, 10)));

                crPage.add(crbackHome);
                crPage.add(Box.createRigidArea(new Dimension(0, 20)));
                crPage.add(crLabel);
                crPage.add(Box.createRigidArea(new Dimension(0, 20)));
                crPage.add(infoPanel);
                infoPanel.add(crName);
                infoPanel.add(email);
                infoPanel.add(whatsapp);

                // ------------------------------------------------------
                // Handle button clicks
                viewRoutine.addActionListener(e -> cardLayout.show(cardPanel, "Routine"));
                viewCourse.addActionListener(e -> cardLayout.show(cardPanel, "Course"));
                contactCR.addActionListener(e -> cardLayout.show(cardPanel, "CR"));
                exitButton.addActionListener(e -> System.exit(1));
                // ------------------------------------------------------
                // Add pages to cardPanel
                cardPanel.add(homePage, "Home");
                cardPanel.add(routinePage, "Routine");
                cardPanel.add(courseListPage, "Course");
                cardPanel.add(crPage, "CR");
                add(cardPanel);

        }

}

class Main {
        public static void main(String[] args) {
                new Routine().setVisible(true);
        }
}