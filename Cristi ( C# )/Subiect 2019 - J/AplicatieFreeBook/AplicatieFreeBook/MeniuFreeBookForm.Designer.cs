namespace AplicatieFreeBook
{
    partial class MeniuFreeBookForm
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea3 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend3 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title3 = new System.Windows.Forms.DataVisualization.Charting.Title();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea4 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend4 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series4 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title4 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.dgw = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.pbLoader = new System.Windows.Forms.PictureBox();
            this.bookCount = new System.Windows.Forms.Label();
            this.dgwImprumuturi = new System.Windows.Forms.DataGridView();
            this.Index = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Titlu = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Autor = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Data_imprumut = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Data_disponibilitate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.tabControl2 = new System.Windows.Forms.TabControl();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.chtNumarU = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.cmbAn = new System.Windows.Forms.ComboBox();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.chtPie = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.lblEmail = new System.Windows.Forms.Label();
            this.btnClose = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbLoader)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwImprumuturi)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.tabControl2.SuspendLayout();
            this.tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chtNumarU)).BeginInit();
            this.tabPage5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chtPie)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Location = new System.Drawing.Point(2, 54);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(796, 394);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.dgw);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(788, 368);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Carti disponibile";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // dgw
            // 
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Location = new System.Drawing.Point(0, 0);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(788, 368);
            this.dgw.TabIndex = 0;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.pbLoader);
            this.tabPage2.Controls.Add(this.bookCount);
            this.tabPage2.Controls.Add(this.dgwImprumuturi);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(788, 368);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Carti imprumutate";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // pbLoader
            // 
            this.pbLoader.Location = new System.Drawing.Point(423, 312);
            this.pbLoader.Name = "pbLoader";
            this.pbLoader.Size = new System.Drawing.Size(306, 50);
            this.pbLoader.TabIndex = 2;
            this.pbLoader.TabStop = false;
            // 
            // bookCount
            // 
            this.bookCount.AutoSize = true;
            this.bookCount.Location = new System.Drawing.Point(36, 332);
            this.bookCount.Name = "bookCount";
            this.bookCount.Size = new System.Drawing.Size(35, 13);
            this.bookCount.TabIndex = 1;
            this.bookCount.Text = "label1";
            // 
            // dgwImprumuturi
            // 
            this.dgwImprumuturi.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwImprumuturi.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Index,
            this.Titlu,
            this.Autor,
            this.Data_imprumut,
            this.Data_disponibilitate});
            this.dgwImprumuturi.Location = new System.Drawing.Point(-4, 0);
            this.dgwImprumuturi.Name = "dgwImprumuturi";
            this.dgwImprumuturi.Size = new System.Drawing.Size(792, 298);
            this.dgwImprumuturi.TabIndex = 0;
            this.dgwImprumuturi.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgwImprumuturi_CellClick);
            // 
            // Index
            // 
            this.Index.HeaderText = "Index";
            this.Index.Name = "Index";
            // 
            // Titlu
            // 
            this.Titlu.HeaderText = "Titlu";
            this.Titlu.Name = "Titlu";
            // 
            // Autor
            // 
            this.Autor.HeaderText = "Autor";
            this.Autor.Name = "Autor";
            // 
            // Data_imprumut
            // 
            this.Data_imprumut.HeaderText = "Data imprumut";
            this.Data_imprumut.Name = "Data_imprumut";
            // 
            // Data_disponibilitate
            // 
            this.Data_disponibilitate.HeaderText = "Data disponibilitate";
            this.Data_disponibilitate.Name = "Data_disponibilitate";
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.tabControl2);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(788, 368);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Statistici biblioteca";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // tabControl2
            // 
            this.tabControl2.Controls.Add(this.tabPage4);
            this.tabControl2.Controls.Add(this.tabPage5);
            this.tabControl2.Location = new System.Drawing.Point(0, 4);
            this.tabControl2.Name = "tabControl2";
            this.tabControl2.SelectedIndex = 0;
            this.tabControl2.Size = new System.Drawing.Size(785, 361);
            this.tabControl2.TabIndex = 0;
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.chtNumarU);
            this.tabPage4.Controls.Add(this.cmbAn);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(777, 335);
            this.tabPage4.TabIndex = 0;
            this.tabPage4.Text = "Numar utilizatori";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // chtNumarU
            // 
            chartArea3.AlignmentOrientation = System.Windows.Forms.DataVisualization.Charting.AreaAlignmentOrientations.Horizontal;
            chartArea3.Name = "ChartArea1";
            this.chtNumarU.ChartAreas.Add(chartArea3);
            this.chtNumarU.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            legend3.Alignment = System.Drawing.StringAlignment.Center;
            legend3.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Bottom;
            legend3.ItemColumnSeparator = System.Windows.Forms.DataVisualization.Charting.LegendSeparatorStyle.Line;
            legend3.Name = "Legend1";
            this.chtNumarU.Legends.Add(legend3);
            this.chtNumarU.Location = new System.Drawing.Point(3, 46);
            this.chtNumarU.Name = "chtNumarU";
            series3.ChartArea = "ChartArea1";
            series3.CustomProperties = "DrawingStyle=Emboss, PointWidth=0.6, MinPixelPointWidth=1";
            series3.EmptyPointStyle.IsValueShownAsLabel = true;
            series3.IsValueShownAsLabel = true;
            series3.Legend = "Legend1";
            series3.LegendText = "Luna";
            series3.MarkerBorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            series3.MarkerBorderWidth = 4;
            series3.MarkerColor = System.Drawing.Color.Maroon;
            series3.Name = "Numar de utilizatori";
            series3.SmartLabelStyle.AllowOutsidePlotArea = System.Windows.Forms.DataVisualization.Charting.LabelOutsidePlotAreaStyle.Yes;
            series3.SmartLabelStyle.IsMarkerOverlappingAllowed = true;
            series3.SmartLabelStyle.IsOverlappedHidden = false;
            series3.XValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.String;
            series3.YValueType = System.Windows.Forms.DataVisualization.Charting.ChartValueType.Int32;
            this.chtNumarU.Series.Add(series3);
            this.chtNumarU.Size = new System.Drawing.Size(771, 286);
            this.chtNumarU.TabIndex = 2;
            this.chtNumarU.Text = "chart1";
            title3.Alignment = System.Drawing.ContentAlignment.BottomCenter;
            title3.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Left;
            title3.Name = "Numarul de utilizatori din anul curent";
            title3.Text = "Numar de utilizatori din anul curent";
            this.chtNumarU.Titles.Add(title3);
            // 
            // cmbAn
            // 
            this.cmbAn.FormattingEnabled = true;
            this.cmbAn.Items.AddRange(new object[] {
            "Niciun filtru"});
            this.cmbAn.Location = new System.Drawing.Point(49, 17);
            this.cmbAn.Name = "cmbAn";
            this.cmbAn.Size = new System.Drawing.Size(114, 21);
            this.cmbAn.TabIndex = 1;
            this.cmbAn.SelectedIndexChanged += new System.EventHandler(this.cmbAn_SelectedIndexChanged);
            // 
            // tabPage5
            // 
            this.tabPage5.Controls.Add(this.chtPie);
            this.tabPage5.Location = new System.Drawing.Point(4, 22);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage5.Size = new System.Drawing.Size(777, 335);
            this.tabPage5.TabIndex = 1;
            this.tabPage5.Text = "Carti populare";
            this.tabPage5.UseVisualStyleBackColor = true;
            // 
            // chtPie
            // 
            chartArea4.Name = "ChartArea1";
            this.chtPie.ChartAreas.Add(chartArea4);
            legend4.Alignment = System.Drawing.StringAlignment.Center;
            legend4.BorderColor = System.Drawing.Color.Black;
            legend4.BorderWidth = 3;
            legend4.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Bottom;
            legend4.Name = "Legend1";
            legend4.Title = "Carti imprumutate";
            this.chtPie.Legends.Add(legend4);
            this.chtPie.Location = new System.Drawing.Point(0, 0);
            this.chtPie.Name = "chtPie";
            series4.ChartArea = "ChartArea1";
            series4.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Pie;
            series4.IsXValueIndexed = true;
            series4.Legend = "Legend1";
            series4.Name = "Series1";
            this.chtPie.Series.Add(series4);
            this.chtPie.Size = new System.Drawing.Size(781, 335);
            this.chtPie.TabIndex = 0;
            this.chtPie.Text = "chart1";
            title4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);
            title4.Name = "Title1";
            title4.Text = "Carti populare";
            this.chtPie.Titles.Add(title4);
            // 
            // lblEmail
            // 
            this.lblEmail.AutoSize = true;
            this.lblEmail.Location = new System.Drawing.Point(28, 26);
            this.lblEmail.Name = "lblEmail";
            this.lblEmail.Size = new System.Drawing.Size(35, 13);
            this.lblEmail.TabIndex = 1;
            this.lblEmail.Text = "label1";
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(641, 12);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(134, 41);
            this.btnClose.TabIndex = 2;
            this.btnClose.Text = "Inchide aplicatia";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // MeniuFreeBookForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.lblEmail);
            this.Controls.Add(this.tabControl1);
            this.Name = "MeniuFreeBookForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "MeniuFreeBookForm";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbLoader)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dgwImprumuturi)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabControl2.ResumeLayout(false);
            this.tabPage4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chtNumarU)).EndInit();
            this.tabPage5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chtPie)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Label lblEmail;
        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.DataGridView dgwImprumuturi;
        private System.Windows.Forms.DataGridViewTextBoxColumn Index;
        private System.Windows.Forms.DataGridViewTextBoxColumn Titlu;
        private System.Windows.Forms.DataGridViewTextBoxColumn Autor;
        private System.Windows.Forms.DataGridViewTextBoxColumn Data_imprumut;
        private System.Windows.Forms.DataGridViewTextBoxColumn Data_disponibilitate;
        private System.Windows.Forms.Label bookCount;
        private System.Windows.Forms.PictureBox pbLoader;
        private System.Windows.Forms.TabControl tabControl2;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.ComboBox cmbAn;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtNumarU;
        private System.Windows.Forms.DataVisualization.Charting.Chart chtPie;
        private System.Windows.Forms.Button btnClose;
    }
}