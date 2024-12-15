package MainFrames;

import GUI.GFrame;
import GUI.GTextArea;
import javax.swing.*;
import javax.swing.event.MouseInputAdapter;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.net.URL;
import java.util.Objects;

public class AboutDU extends GFrame{

    public AboutDU() {
        setTitle("About University - ");
        setPreferredSize(new Dimension(850,700));
        setResizable(false);

        JPanel bg = new JPanel(null);
        bg.setPreferredSize(new Dimension(840,1525));
        setContentPane(new JScrollPane(bg,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));

        JLabel heading = new JLabel("Delhi University", resize(getClass().getClassLoader().getResource("DU_logo.png"), new Dimension(65,65)),LEFT);
        heading.setHorizontalAlignment(CENTER);
        heading.setBorder(BorderFactory.createTitledBorder(Round_Title_border));
        heading.setIconTextGap(20);
        heading.setFont(new Font("Segoe Print", Font.BOLD, 26));
        heading.setBounds(200,10,400,80);
        heading.setOpaque(true);
        heading.addMouseListener(new MouseInputAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                try {
                    Desktop.getDesktop().browse(new URL("http://du.ac.in/").toURI());
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            }
        });
        bg.add(heading);

        try {
            JLabel logo = new JLabel(resize(getClass().getClassLoader().getResource("aboutdu.jpg"),new Dimension(500,300)));
            logo.setLabelFor(heading);
            logo.setHorizontalAlignment(CENTER);
            logo.setBackground(new Color(50, 115, 212, 205));
            logo.setBounds(150,100,500,300);
            bg.add(logo);

            GTextArea details = new GTextArea(GTextArea.SCROLLBARS_VERTICAL_ONLY);
            details.setFont(new Font("Segoe UI Semibold", Font.BOLD, 16));
            details.setEditable(false);
            details.setForeground(Color.blue);
            details.setWrapping(true);
            details.setBackground(Color.PINK);
            details.setText("\t\t\t\t\t\t \"About Delhi University\"\n\nThe University of Delhi is a premier university of the country with a venerable legacy and international acclaim for highest academic standards, diverse educational programmes, distinguished faculty, illustrious alumni, varied co-curricular activities and modern infrastructure. Over the many years of its existence, the University has sustained the highest global standards and best practices in higher education. Its long-term commitment to nation building and unflinching adherence to universal human values are reflected in its motto: 'Nishtha Dhriti Satyam'(Dedication, Steadfastness and Truth).\r\n\r\nEstablished in 1922 as a unitary, teaching and residential University by the Act of the then Central Legislative Assembly, a strong commitment to excellence in teaching, research and social outreach has made the University a role-model and trend setter for other universities. The President of India is the Visitor, the Vice-President is the Chancellor and the Chief Justice of the Supreme Court of India is the Pro-Chancellor of the University. Beginning with three colleges and 750 students, it has grown as one of the largest universities in India with 16 faculties, over 80 academic departments, an equal number of colleges and over seven lakh students. Over 500 programmes offered by the University are approved by Academic and Executive Councils, out of which 209 programmes are being considered for NAAC accreditation purpose. The rest being run in colleges are separately accredited.\r\n\r\nDrawing students and faculty from across India and abroad, the University has emerged as a symbol of excellence, integrity and openness of mansa (thought), vaacha (speech) and karmana (action). \r\n\r\nSir Maurice Gwyer, the then Vice-Chancellor, realizing the importance of a distinguished faculty to act as role models, relentlessly searched for talent all over the country and roped in men of eminence to this University, such as Prof. D.S. Kothari in Physics, Prof. T.R. Sheshadri in Chemistry, Prof. P Maheshwari in Botany and Prof. M L Bhatia in Zoology.\r\n\r\nFive Departments namely Chemistry, Geology, Zoology, Sociology and History have been awarded the status of the Centres of Advanced Studies. These Centres of Advanced Studies have carved a niche for themselves as centres of excellence in teaching and research in their respective areas. In addition, a good number of University departments are also receiving grants under the Special Assistance Programme of the UGC in recognition of their outstanding academic work. 10 Departments (Germanic &amp; Romance Studies, Hindi, Persian, Geography, Music, East Asian Studies, Anthropology, Mathematics, B.R.Ambedkar, M. I.L.) are getting grants under DRS, 2 Departments (Buddhist Studies, English) are getting grants under DSA, 3 Departments (English, Buddhist Studies, Social Work) are getting grants under AISHSS and 3 Departments (African Studies, East Asian Studies, Developing Countries Research Centre) are getting grants under Area Studies Programmes. Department of Adult, Continuing Education and Extension and Women&rsquo;s Studies &amp; Development Centre of the University are also getting special funding from UGC. The University today boasts of as many as 15 big libraries apart from libraries in colleges. The University Science Instrumentation Centre (USIC) which is now situated close to the Physics and Chemistry Departments houses a number of sophisticated and high-end research instruments. These instruments are used quite frequently by Teachers and Research Scholars of postgraduate departments of the University as well as by many other institutions in Delhi and its neighbourhood. The University has recently laid fibre-optic network in the North and the South Campuses connecting all colleges and departments. \r\n\r\nWhen the University of Delhi expanded in many directions to keep pace with a rapidly growing city, South Campus was established in 1973 to facilitate access for the residents of South Delhi. It moved to its present location on Benito Juarez Road, near Dhaula Kuan, in 1984. The Campus is now spread across 69 acres of green, hilly terrain and its buildings blend attractively with the natural surroundings. The various departments are located in the Faculty of Arts and the Faculty of Inter-disciplinary and Applied Sciences. S.P. Jain Centre for Management Studies is also located at the South Delhi Campus. Besides these, the Campus has a good library, a Health Centre, a Bank, a Post Office, DTC Pass Section and administrative and examination blocks. South Campus also provides some residential quarters for faculty members and the non-teaching staff. Outstation students are offered accommodation in three hostels.");
            details.setBounds(5,420,800,600);
            bg.add(details);

            JLabel last = new JLabel(new ImageIcon(Objects.requireNonNull(getClass().getClassLoader().getResource("about.gif"))));
            last.setLabelFor(heading);
            last.setHorizontalAlignment(CENTER);
            last.setBounds(5,1025,800,500);
            bg.add(last);
        } catch (Exception e) {
            e.printStackTrace();
        }

        JButton btn = getMainbtn(650,10);
        bg.add(btn);
        pack();
    }
}
