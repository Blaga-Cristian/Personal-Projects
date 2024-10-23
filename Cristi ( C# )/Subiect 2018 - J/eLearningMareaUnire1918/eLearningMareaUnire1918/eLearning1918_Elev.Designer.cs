namespace eLearningMareaUnire1918
{
    partial class eLearning1918_Elev
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.tsmielev = new System.Windows.Forms.ToolStripMenuItem();
            this.testeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.carnetDeNoteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.graficNoteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.iesireToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tbc = new System.Windows.Forms.TabControl();
            this.tbpTeste = new System.Windows.Forms.TabPage();
            this.gb = new System.Windows.Forms.GroupBox();
            this.btnAns = new System.Windows.Forms.Button();
            this.btnUrm = new System.Windows.Forms.Button();
            this.chk42 = new System.Windows.Forms.CheckBox();
            this.chk41 = new System.Windows.Forms.CheckBox();
            this.chk34 = new System.Windows.Forms.CheckBox();
            this.chk33 = new System.Windows.Forms.CheckBox();
            this.chk32 = new System.Windows.Forms.CheckBox();
            this.chk31 = new System.Windows.Forms.CheckBox();
            this.txt1 = new System.Windows.Forms.TextBox();
            this.lbl1 = new System.Windows.Forms.Label();
            this.chk24 = new System.Windows.Forms.CheckBox();
            this.chk23 = new System.Windows.Forms.CheckBox();
            this.chk22 = new System.Windows.Forms.CheckBox();
            this.chk21 = new System.Windows.Forms.CheckBox();
            this.txtInt = new System.Windows.Forms.TextBox();
            this.lblItem = new System.Windows.Forms.Label();
            this.lblPunctaj = new System.Windows.Forms.Label();
            this.btnStartTest = new System.Windows.Forms.Button();
            this.tbpCarnet = new System.Windows.Forms.TabPage();
            this.dgwCarnet = new System.Windows.Forms.DataGridView();
            this.lblCarnet = new System.Windows.Forms.Label();
            this.tbpGrafic = new System.Windows.Forms.TabPage();
            this.chtNote = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.btnPre = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            this.tbc.SuspendLayout();
            this.tbpTeste.SuspendLayout();
            this.gb.SuspendLayout();
            this.tbpCarnet.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwCarnet)).BeginInit();
            this.tbpGrafic.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chtNote)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmielev});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // tsmielev
            // 
            this.tsmielev.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.testeToolStripMenuItem,
            this.carnetDeNoteToolStripMenuItem,
            this.graficNoteToolStripMenuItem,
            this.iesireToolStripMenuItem});
            this.tsmielev.Name = "tsmielev";
            this.tsmielev.Size = new System.Drawing.Size(40, 20);
            this.tsmielev.Text = "Elev";
            // 
            // testeToolStripMenuItem
            // 
            this.testeToolStripMenuItem.Name = "testeToolStripMenuItem";
            this.testeToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.testeToolStripMenuItem.Text = "Teste";
            this.testeToolStripMenuItem.Click += new System.EventHandler(this.testeToolStripMenuItem_Click);
            // 
            // carnetDeNoteToolStripMenuItem
            // 
            this.carnetDeNoteToolStripMenuItem.Name = "carnetDeNoteToolStripMenuItem";
            this.carnetDeNoteToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.carnetDeNoteToolStripMenuItem.Text = "Carnet de note";
            this.carnetDeNoteToolStripMenuItem.Click += new System.EventHandler(this.carnetDeNoteToolStripMenuItem_Click);
            // 
            // graficNoteToolStripMenuItem
            // 
            this.graficNoteToolStripMenuItem.Name = "graficNoteToolStripMenuItem";
            this.graficNoteToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.graficNoteToolStripMenuItem.Text = "Grafic note";
            this.graficNoteToolStripMenuItem.Click += new System.EventHandler(this.graficNoteToolStripMenuItem_Click);
            // 
            // iesireToolStripMenuItem
            // 
            this.iesireToolStripMenuItem.Name = "iesireToolStripMenuItem";
            this.iesireToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.iesireToolStripMenuItem.Text = "Iesire";
            this.iesireToolStripMenuItem.Click += new System.EventHandler(this.iesireToolStripMenuItem_Click);
            // 
            // tbc
            // 
            this.tbc.Controls.Add(this.tbpTeste);
            this.tbc.Controls.Add(this.tbpCarnet);
            this.tbc.Controls.Add(this.tbpGrafic);
            this.tbc.Location = new System.Drawing.Point(0, 27);
            this.tbc.Name = "tbc";
            this.tbc.SelectedIndex = 0;
            this.tbc.Size = new System.Drawing.Size(800, 426);
            this.tbc.TabIndex = 1;
            this.tbc.SelectedIndexChanged += new System.EventHandler(this.tbc_SelectedIndexChanged);
            // 
            // tbpTeste
            // 
            this.tbpTeste.Controls.Add(this.gb);
            this.tbpTeste.Controls.Add(this.lblPunctaj);
            this.tbpTeste.Controls.Add(this.btnStartTest);
            this.tbpTeste.Location = new System.Drawing.Point(4, 22);
            this.tbpTeste.Name = "tbpTeste";
            this.tbpTeste.Padding = new System.Windows.Forms.Padding(3);
            this.tbpTeste.Size = new System.Drawing.Size(792, 400);
            this.tbpTeste.TabIndex = 0;
            this.tbpTeste.Text = "Teste";
            this.tbpTeste.UseVisualStyleBackColor = true;
            // 
            // gb
            // 
            this.gb.BackColor = System.Drawing.Color.LightGray;
            this.gb.Controls.Add(this.btnAns);
            this.gb.Controls.Add(this.btnUrm);
            this.gb.Controls.Add(this.chk42);
            this.gb.Controls.Add(this.chk41);
            this.gb.Controls.Add(this.chk34);
            this.gb.Controls.Add(this.chk33);
            this.gb.Controls.Add(this.chk32);
            this.gb.Controls.Add(this.chk31);
            this.gb.Controls.Add(this.txt1);
            this.gb.Controls.Add(this.lbl1);
            this.gb.Controls.Add(this.chk24);
            this.gb.Controls.Add(this.chk23);
            this.gb.Controls.Add(this.chk22);
            this.gb.Controls.Add(this.chk21);
            this.gb.Controls.Add(this.txtInt);
            this.gb.Controls.Add(this.lblItem);
            this.gb.Location = new System.Drawing.Point(157, 61);
            this.gb.Name = "gb";
            this.gb.Size = new System.Drawing.Size(627, 328);
            this.gb.TabIndex = 2;
            this.gb.TabStop = false;
            // 
            // btnAns
            // 
            this.btnAns.Location = new System.Drawing.Point(302, 295);
            this.btnAns.Name = "btnAns";
            this.btnAns.Size = new System.Drawing.Size(75, 23);
            this.btnAns.TabIndex = 15;
            this.btnAns.Text = "Raspunde";
            this.btnAns.UseVisualStyleBackColor = true;
            this.btnAns.Click += new System.EventHandler(this.btnAns_Click);
            // 
            // btnUrm
            // 
            this.btnUrm.Location = new System.Drawing.Point(518, 291);
            this.btnUrm.Name = "btnUrm";
            this.btnUrm.Size = new System.Drawing.Size(103, 31);
            this.btnUrm.TabIndex = 14;
            this.btnUrm.Text = "Urmatorul";
            this.btnUrm.UseVisualStyleBackColor = true;
            this.btnUrm.Click += new System.EventHandler(this.btnUrm_Click);
            // 
            // chk42
            // 
            this.chk42.AutoSize = true;
            this.chk42.Location = new System.Drawing.Point(188, 170);
            this.chk42.Name = "chk42";
            this.chk42.Size = new System.Drawing.Size(80, 17);
            this.chk42.TabIndex = 13;
            this.chk42.Text = "checkBox2";
            this.chk42.UseVisualStyleBackColor = true;
            this.chk42.Visible = false;
            // 
            // chk41
            // 
            this.chk41.AutoSize = true;
            this.chk41.Location = new System.Drawing.Point(188, 147);
            this.chk41.Name = "chk41";
            this.chk41.Size = new System.Drawing.Size(56, 17);
            this.chk41.TabIndex = 12;
            this.chk41.Text = "chk31";
            this.chk41.UseVisualStyleBackColor = true;
            this.chk41.Visible = false;
            // 
            // chk34
            // 
            this.chk34.AutoSize = true;
            this.chk34.Location = new System.Drawing.Point(69, 206);
            this.chk34.Name = "chk34";
            this.chk34.Size = new System.Drawing.Size(80, 17);
            this.chk34.TabIndex = 11;
            this.chk34.Text = "checkBox4";
            this.chk34.UseVisualStyleBackColor = true;
            this.chk34.Visible = false;
            // 
            // chk33
            // 
            this.chk33.AutoSize = true;
            this.chk33.Location = new System.Drawing.Point(69, 183);
            this.chk33.Name = "chk33";
            this.chk33.Size = new System.Drawing.Size(80, 17);
            this.chk33.TabIndex = 10;
            this.chk33.Text = "checkBox3";
            this.chk33.UseVisualStyleBackColor = true;
            this.chk33.Visible = false;
            // 
            // chk32
            // 
            this.chk32.AutoSize = true;
            this.chk32.Location = new System.Drawing.Point(69, 160);
            this.chk32.Name = "chk32";
            this.chk32.Size = new System.Drawing.Size(80, 17);
            this.chk32.TabIndex = 9;
            this.chk32.Text = "checkBox2";
            this.chk32.UseVisualStyleBackColor = true;
            this.chk32.Visible = false;
            // 
            // chk31
            // 
            this.chk31.AutoSize = true;
            this.chk31.Location = new System.Drawing.Point(69, 137);
            this.chk31.Name = "chk31";
            this.chk31.Size = new System.Drawing.Size(80, 17);
            this.chk31.TabIndex = 8;
            this.chk31.Text = "checkBox1";
            this.chk31.UseVisualStyleBackColor = true;
            this.chk31.Visible = false;
            // 
            // txt1
            // 
            this.txt1.Location = new System.Drawing.Point(102, 109);
            this.txt1.Name = "txt1";
            this.txt1.Size = new System.Drawing.Size(156, 20);
            this.txt1.TabIndex = 7;
            this.txt1.Visible = false;
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Location = new System.Drawing.Point(49, 112);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(49, 13);
            this.lbl1.TabIndex = 6;
            this.lbl1.Text = "Raspuns";
            this.lbl1.Visible = false;
            // 
            // chk24
            // 
            this.chk24.AutoSize = true;
            this.chk24.Location = new System.Drawing.Point(52, 206);
            this.chk24.Name = "chk24";
            this.chk24.Size = new System.Drawing.Size(80, 17);
            this.chk24.TabIndex = 5;
            this.chk24.Text = "checkBox4";
            this.chk24.UseVisualStyleBackColor = true;
            this.chk24.Visible = false;
            // 
            // chk23
            // 
            this.chk23.AutoSize = true;
            this.chk23.Location = new System.Drawing.Point(52, 183);
            this.chk23.Name = "chk23";
            this.chk23.Size = new System.Drawing.Size(80, 17);
            this.chk23.TabIndex = 4;
            this.chk23.Text = "checkBox3";
            this.chk23.UseVisualStyleBackColor = true;
            this.chk23.Visible = false;
            // 
            // chk22
            // 
            this.chk22.AutoSize = true;
            this.chk22.Location = new System.Drawing.Point(52, 160);
            this.chk22.Name = "chk22";
            this.chk22.Size = new System.Drawing.Size(80, 17);
            this.chk22.TabIndex = 3;
            this.chk22.Text = "checkBox2";
            this.chk22.UseVisualStyleBackColor = true;
            this.chk22.Visible = false;
            // 
            // chk21
            // 
            this.chk21.AutoSize = true;
            this.chk21.Location = new System.Drawing.Point(52, 137);
            this.chk21.Name = "chk21";
            this.chk21.Size = new System.Drawing.Size(80, 17);
            this.chk21.TabIndex = 2;
            this.chk21.Text = "checkBox1";
            this.chk21.UseVisualStyleBackColor = true;
            this.chk21.Visible = false;
            // 
            // txtInt
            // 
            this.txtInt.Location = new System.Drawing.Point(102, 19);
            this.txtInt.Multiline = true;
            this.txtInt.Name = "txtInt";
            this.txtInt.Size = new System.Drawing.Size(420, 78);
            this.txtInt.TabIndex = 1;
            // 
            // lblItem
            // 
            this.lblItem.AutoSize = true;
            this.lblItem.Location = new System.Drawing.Point(49, 49);
            this.lblItem.Name = "lblItem";
            this.lblItem.Size = new System.Drawing.Size(0, 13);
            this.lblItem.TabIndex = 0;
            // 
            // lblPunctaj
            // 
            this.lblPunctaj.AutoSize = true;
            this.lblPunctaj.Location = new System.Drawing.Point(154, 34);
            this.lblPunctaj.Name = "lblPunctaj";
            this.lblPunctaj.Size = new System.Drawing.Size(55, 13);
            this.lblPunctaj.TabIndex = 1;
            this.lblPunctaj.Text = "Punctaj: 1";
            // 
            // btnStartTest
            // 
            this.btnStartTest.Location = new System.Drawing.Point(8, 20);
            this.btnStartTest.Name = "btnStartTest";
            this.btnStartTest.Size = new System.Drawing.Size(88, 27);
            this.btnStartTest.TabIndex = 0;
            this.btnStartTest.Text = "Start test";
            this.btnStartTest.UseVisualStyleBackColor = true;
            this.btnStartTest.Click += new System.EventHandler(this.btnStartTest_Click);
            // 
            // tbpCarnet
            // 
            this.tbpCarnet.Controls.Add(this.btnPre);
            this.tbpCarnet.Controls.Add(this.dgwCarnet);
            this.tbpCarnet.Controls.Add(this.lblCarnet);
            this.tbpCarnet.Location = new System.Drawing.Point(4, 22);
            this.tbpCarnet.Name = "tbpCarnet";
            this.tbpCarnet.Padding = new System.Windows.Forms.Padding(3);
            this.tbpCarnet.Size = new System.Drawing.Size(792, 400);
            this.tbpCarnet.TabIndex = 1;
            this.tbpCarnet.Text = "Carnet de note";
            this.tbpCarnet.UseVisualStyleBackColor = true;
            // 
            // dgwCarnet
            // 
            this.dgwCarnet.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwCarnet.Location = new System.Drawing.Point(8, 105);
            this.dgwCarnet.Name = "dgwCarnet";
            this.dgwCarnet.Size = new System.Drawing.Size(776, 289);
            this.dgwCarnet.TabIndex = 1;
            // 
            // lblCarnet
            // 
            this.lblCarnet.AutoSize = true;
            this.lblCarnet.Location = new System.Drawing.Point(151, 33);
            this.lblCarnet.Name = "lblCarnet";
            this.lblCarnet.Size = new System.Drawing.Size(41, 13);
            this.lblCarnet.TabIndex = 0;
            this.lblCarnet.Text = "sadsad";
            // 
            // tbpGrafic
            // 
            this.tbpGrafic.Controls.Add(this.chtNote);
            this.tbpGrafic.Location = new System.Drawing.Point(4, 22);
            this.tbpGrafic.Name = "tbpGrafic";
            this.tbpGrafic.Padding = new System.Windows.Forms.Padding(3);
            this.tbpGrafic.Size = new System.Drawing.Size(792, 400);
            this.tbpGrafic.TabIndex = 2;
            this.tbpGrafic.Text = "Grafic note";
            this.tbpGrafic.UseVisualStyleBackColor = true;
            // 
            // chtNote
            // 
            chartArea1.Name = "ChartArea1";
            this.chtNote.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chtNote.Legends.Add(legend1);
            this.chtNote.Location = new System.Drawing.Point(8, 50);
            this.chtNote.Name = "chtNote";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            series1.YValuesPerPoint = 2;
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series2.Legend = "Legend1";
            series2.Name = "Series2";
            this.chtNote.Series.Add(series1);
            this.chtNote.Series.Add(series2);
            this.chtNote.Size = new System.Drawing.Size(776, 315);
            this.chtNote.TabIndex = 0;
            this.chtNote.Text = "chart1";
            title1.Name = "Title1";
            title1.Text = "Graficul notelor";
            this.chtNote.Titles.Add(title1);
            // 
            // btnPre
            // 
            this.btnPre.Location = new System.Drawing.Point(510, 33);
            this.btnPre.Name = "btnPre";
            this.btnPre.Size = new System.Drawing.Size(133, 25);
            this.btnPre.TabIndex = 2;
            this.btnPre.Text = "Previzualizare";
            this.btnPre.UseVisualStyleBackColor = true;
            this.btnPre.Click += new System.EventHandler(this.btnPre_Click);
            // 
            // eLearning1918_Elev
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tbc);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "eLearning1918_Elev";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "eLearning1918_Elev";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.tbc.ResumeLayout(false);
            this.tbpTeste.ResumeLayout(false);
            this.tbpTeste.PerformLayout();
            this.gb.ResumeLayout(false);
            this.gb.PerformLayout();
            this.tbpCarnet.ResumeLayout(false);
            this.tbpCarnet.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwCarnet)).EndInit();
            this.tbpGrafic.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chtNote)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem tsmielev;
        private System.Windows.Forms.ToolStripMenuItem testeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem carnetDeNoteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem graficNoteToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem iesireToolStripMenuItem;
        private System.Windows.Forms.TabControl tbc;
        private System.Windows.Forms.TabPage tbpTeste;
        private System.Windows.Forms.GroupBox gb;
        private System.Windows.Forms.Label lblPunctaj;
        private System.Windows.Forms.Button btnStartTest;
        private System.Windows.Forms.TabPage tbpCarnet;
        private System.Windows.Forms.TabPage tbpGrafic;
        private System.Windows.Forms.TextBox txtInt;
        private System.Windows.Forms.Label lblItem;
        private System.Windows.Forms.CheckBox chk24;
        private System.Windows.Forms.CheckBox chk23;
        private System.Windows.Forms.CheckBox chk22;
        private System.Windows.Forms.CheckBox chk21;
        private System.Windows.Forms.TextBox txt1;
        private System.Windows.Forms.Label lbl1;
        private System.Windows.Forms.Button btnAns;
        private System.Windows.Forms.Button btnUrm;
        private System.Windows.Forms.CheckBox chk42;
        private System.Windows.Forms.CheckBox chk41;
        private System.Windows.Forms.CheckBox chk34;
        private System.Windows.Forms.CheckBox chk33;
        private System.Windows.Forms.CheckBox chk32;
        private System.Windows.Forms.CheckBox chk31;
        private System.Windows.Forms.DataGridView dgwCarnet;
        private System.Windows.Forms.Label lblCarnet;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtNote;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Button btnPre;
    }
}