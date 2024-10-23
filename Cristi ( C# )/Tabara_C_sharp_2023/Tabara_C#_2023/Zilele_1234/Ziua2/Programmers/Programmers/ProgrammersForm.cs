using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Programmers
{
    public partial class ProgrammersForm : Form
    {
        List<Programmer> programmers = new List<Programmer>();
        public ProgrammersForm()
        {
            InitializeComponent();
        }

        private void ProgrammersForm_Load(object sender, EventArgs e)
        {
            ReadProgrammers();
            dgw.DataSource = programmers;
            cmbNames.DataSource = programmers;
            cmbNames.DisplayMember = "Name";
            cmbNames.ValueMember = "Position";
            lblPosition.Text = cmbNames.SelectedValue.ToString();
            lstSalary.DataSource = programmers;
            lstSalary.DisplayMember = "Salary";
        }

        private void ReadProgrammers()
        {
            StreamReader sr = new StreamReader("programmers.in");
            string line;
            string[] s;
            char[] sep = { ';' };
            while ((line = sr.ReadLine()) != null)
            {
                s = line.Split(sep, StringSplitOptions.RemoveEmptyEntries);

                string name = s[0];
                string position = s[1];
                int salary = int.Parse(s[2]);
                DateTime hiringDate = DateTime.Parse(s[3]);
                programmers.Add(new Programmer(name, position, salary, hiringDate));
            }

            sr.Close();
        }

        private void cmbNames_SelectedIndexChanged(object sender, EventArgs e)
        {
            lblPosition.Text = cmbNames.SelectedValue.ToString();
        }
    }
}
