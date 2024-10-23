namespace Turismul_Durabil
{
    partial class Vizualizare_excursie
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
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.dtpStart = new System.Windows.Forms.DateTimePicker();
            this.dtpStop = new System.Windows.Forms.DateTimePicker();
            this.label2 = new System.Windows.Forms.Label();
            this.btnGen = new System.Windows.Forms.Button();
            this.tbc = new System.Windows.Forms.TabControl();
            this.tbpPlan = new System.Windows.Forms.TabPage();
            this.dgw = new System.Windows.Forms.DataGridView();
            this.tbpPer = new System.Windows.Forms.TabPage();
            this.dgwPer = new System.Windows.Forms.DataGridView();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.dgwItinerariu = new System.Windows.Forms.DataGridView();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.lblData = new System.Windows.Forms.Label();
            this.lblNume = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.prgb = new System.Windows.Forms.ProgressBar();
            this.pb = new System.Windows.Forms.PictureBox();
            this.planificariBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.turismDataSet1 = new Turismul_Durabil.TurismDataSet1();
            this.turismDataSet = new Turismul_Durabil.TurismDataSet();
            this.planificariBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.planificariTableAdapter = new Turismul_Durabil.TurismDataSetTableAdapters.PlanificariTableAdapter();
            this.planificariTableAdapter1 = new Turismul_Durabil.TurismDataSet1TableAdapters.PlanificariTableAdapter();
            this.tbc.SuspendLayout();
            this.tbpPlan.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            this.tbpPer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwPer)).BeginInit();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwItinerariu)).BeginInit();
            this.tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.planificariBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.turismDataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.turismDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.planificariBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Inceput excursie";
            // 
            // dtpStart
            // 
            this.dtpStart.Location = new System.Drawing.Point(12, 37);
            this.dtpStart.Name = "dtpStart";
            this.dtpStart.Size = new System.Drawing.Size(200, 20);
            this.dtpStart.TabIndex = 1;
            // 
            // dtpStop
            // 
            this.dtpStop.Location = new System.Drawing.Point(256, 37);
            this.dtpStop.Name = "dtpStop";
            this.dtpStop.Size = new System.Drawing.Size(200, 20);
            this.dtpStop.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(256, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Sfarsit excursie";
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(510, 22);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(127, 35);
            this.btnGen.TabIndex = 4;
            this.btnGen.Text = "Genereaza excursie";
            this.btnGen.UseVisualStyleBackColor = true;
            this.btnGen.Click += new System.EventHandler(this.btnGen_Click);
            // 
            // tbc
            // 
            this.tbc.Controls.Add(this.tbpPlan);
            this.tbc.Controls.Add(this.tbpPer);
            this.tbc.Controls.Add(this.tabPage3);
            this.tbc.Controls.Add(this.tabPage4);
            this.tbc.Location = new System.Drawing.Point(1, 75);
            this.tbc.Name = "tbc";
            this.tbc.SelectedIndex = 0;
            this.tbc.Size = new System.Drawing.Size(797, 375);
            this.tbc.TabIndex = 5;
            this.tbc.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tbpPlan
            // 
            this.tbpPlan.Controls.Add(this.dgw);
            this.tbpPlan.Location = new System.Drawing.Point(4, 22);
            this.tbpPlan.Name = "tbpPlan";
            this.tbpPlan.Padding = new System.Windows.Forms.Padding(3);
            this.tbpPlan.Size = new System.Drawing.Size(789, 349);
            this.tbpPlan.TabIndex = 0;
            this.tbpPlan.Text = "Planificari";
            this.tbpPlan.UseVisualStyleBackColor = true;
            // 
            // dgw
            // 
            this.dgw.AllowUserToAddRows = false;
            this.dgw.AllowUserToDeleteRows = false;
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Location = new System.Drawing.Point(0, 0);
            this.dgw.Name = "dgw";
            this.dgw.ReadOnly = true;
            this.dgw.Size = new System.Drawing.Size(789, 349);
            this.dgw.TabIndex = 0;
            // 
            // tbpPer
            // 
            this.tbpPer.Controls.Add(this.dgwPer);
            this.tbpPer.Location = new System.Drawing.Point(4, 22);
            this.tbpPer.Name = "tbpPer";
            this.tbpPer.Padding = new System.Windows.Forms.Padding(3);
            this.tbpPer.Size = new System.Drawing.Size(789, 349);
            this.tbpPer.TabIndex = 1;
            this.tbpPer.Text = "Perioada de vizitare";
            this.tbpPer.UseVisualStyleBackColor = true;
            // 
            // dgwPer
            // 
            this.dgwPer.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwPer.Location = new System.Drawing.Point(0, 0);
            this.dgwPer.Name = "dgwPer";
            this.dgwPer.Size = new System.Drawing.Size(789, 349);
            this.dgwPer.TabIndex = 0;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.dgwItinerariu);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(789, 349);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Itinerariu";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // dgwItinerariu
            // 
            this.dgwItinerariu.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwItinerariu.Location = new System.Drawing.Point(0, 0);
            this.dgwItinerariu.Name = "dgwItinerariu";
            this.dgwItinerariu.Size = new System.Drawing.Size(789, 349);
            this.dgwItinerariu.TabIndex = 0;
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.lblData);
            this.tabPage4.Controls.Add(this.lblNume);
            this.tabPage4.Controls.Add(this.btnStart);
            this.tabPage4.Controls.Add(this.prgb);
            this.tabPage4.Controls.Add(this.pb);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(789, 349);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Vizualizare Imagini";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // lblData
            // 
            this.lblData.AutoSize = true;
            this.lblData.Location = new System.Drawing.Point(426, 19);
            this.lblData.Name = "lblData";
            this.lblData.Size = new System.Drawing.Size(0, 13);
            this.lblData.TabIndex = 4;
            // 
            // lblNume
            // 
            this.lblNume.AutoSize = true;
            this.lblNume.Location = new System.Drawing.Point(7, 19);
            this.lblNume.Name = "lblNume";
            this.lblNume.Size = new System.Drawing.Size(0, 13);
            this.lblNume.TabIndex = 3;
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(563, 143);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(156, 53);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // prgb
            // 
            this.prgb.Location = new System.Drawing.Point(528, 48);
            this.prgb.Name = "prgb";
            this.prgb.Size = new System.Drawing.Size(225, 40);
            this.prgb.TabIndex = 1;
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(7, 44);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(454, 246);
            this.pb.TabIndex = 0;
            this.pb.TabStop = false;
            // 
            // planificariBindingSource1
            // 
            this.planificariBindingSource1.DataMember = "Planificari";
            this.planificariBindingSource1.DataSource = this.turismDataSet1;
            // 
            // turismDataSet1
            // 
            this.turismDataSet1.DataSetName = "TurismDataSet1";
            this.turismDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // turismDataSet
            // 
            this.turismDataSet.DataSetName = "TurismDataSet";
            this.turismDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // planificariBindingSource
            // 
            this.planificariBindingSource.DataMember = "Planificari";
            this.planificariBindingSource.DataSource = this.turismDataSet;
            // 
            // planificariTableAdapter
            // 
            this.planificariTableAdapter.ClearBeforeFill = true;
            // 
            // planificariTableAdapter1
            // 
            this.planificariTableAdapter1.ClearBeforeFill = true;
            // 
            // Vizualizare_excursie
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tbc);
            this.Controls.Add(this.btnGen);
            this.Controls.Add(this.dtpStop);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.dtpStart);
            this.Controls.Add(this.label1);
            this.Name = "Vizualizare_excursie";
            this.Text = "Vizualizare_excursie";
            this.tbc.ResumeLayout(false);
            this.tbpPlan.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            this.tbpPer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgwPer)).EndInit();
            this.tabPage3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgwItinerariu)).EndInit();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.planificariBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.turismDataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.turismDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.planificariBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dtpStart;
        private System.Windows.Forms.DateTimePicker dtpStop;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnGen;
        private System.Windows.Forms.TabControl tbc;
        private System.Windows.Forms.TabPage tbpPlan;
        private System.Windows.Forms.TabPage tbpPer;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.DataGridView dgw;
        private TurismDataSet turismDataSet;
        private System.Windows.Forms.BindingSource planificariBindingSource;
        private TurismDataSetTableAdapters.PlanificariTableAdapter planificariTableAdapter;
        private TurismDataSet1 turismDataSet1;
        private System.Windows.Forms.BindingSource planificariBindingSource1;
        private TurismDataSet1TableAdapters.PlanificariTableAdapter planificariTableAdapter1;
        private System.Windows.Forms.DataGridView dgwPer;
        private System.Windows.Forms.DataGridView dgwItinerariu;
        private System.Windows.Forms.Label lblData;
        private System.Windows.Forms.Label lblNume;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.ProgressBar prgb;
        private System.Windows.Forms.PictureBox pb;
    }
}