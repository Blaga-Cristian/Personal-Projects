namespace Good_Food
{
    partial class Optiuni
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tlp = new System.Windows.Forms.TableLayoutPanel();
            this.label4 = new System.Windows.Forms.Label();
            this.btnGen = new System.Windows.Forms.Button();
            this.txtGreutate = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtInaltime = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtVarsta = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.btnComanda = new System.Windows.Forms.Button();
            this.txtPret = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.txtTotalk = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtNecesar = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.dgw = new System.Windows.Forms.DataGridView();
            this.idprodusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.denumireprodusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.descriereDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pretDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.kcalDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.felulDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.meniuBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.gOOD_FOODDataSet = new Good_Food.GOOD_FOODDataSet();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.label10 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnGenereazaMeniuri = new System.Windows.Forms.Button();
            this.txtBuget = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txtKcalZilnice = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.dgwMeniuri = new System.Windows.Forms.DataGridView();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.cht = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.meniuTableAdapter = new Good_Food.GOOD_FOODDataSetTableAdapters.MeniuTableAdapter();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.meniuBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gOOD_FOODDataSet)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwMeniuri)).BeginInit();
            this.tabPage4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.cht)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Location = new System.Drawing.Point(1, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(799, 452);
            this.tabControl1.TabIndex = 0;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.tlp);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.btnGen);
            this.tabPage1.Controls.Add(this.txtGreutate);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.txtInaltime);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.txtVarsta);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(791, 426);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Calculator Kcal";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tlp
            // 
            this.tlp.BackColor = System.Drawing.Color.Silver;
            this.tlp.ColumnCount = 1;
            this.tlp.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 44.11765F));
            this.tlp.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55.88235F));
            this.tlp.Location = new System.Drawing.Point(500, 92);
            this.tlp.Name = "tlp";
            this.tlp.RowCount = 1;
            this.tlp.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tlp.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tlp.Size = new System.Drawing.Size(54, 20);
            this.tlp.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(421, 96);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(73, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Necesar zilnic";
            // 
            // btnGen
            // 
            this.btnGen.Location = new System.Drawing.Point(245, 240);
            this.btnGen.Name = "btnGen";
            this.btnGen.Size = new System.Drawing.Size(102, 48);
            this.btnGen.TabIndex = 6;
            this.btnGen.Text = "Genereaza";
            this.btnGen.UseVisualStyleBackColor = true;
            this.btnGen.Click += new System.EventHandler(this.btnGen_Click);
            // 
            // txtGreutate
            // 
            this.txtGreutate.Location = new System.Drawing.Point(132, 132);
            this.txtGreutate.Name = "txtGreutate";
            this.txtGreutate.Size = new System.Drawing.Size(140, 20);
            this.txtGreutate.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(47, 139);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(69, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Greutate (kg)";
            // 
            // txtInaltime
            // 
            this.txtInaltime.Location = new System.Drawing.Point(132, 89);
            this.txtInaltime.Name = "txtInaltime";
            this.txtInaltime.Size = new System.Drawing.Size(140, 20);
            this.txtInaltime.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(47, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Inaltimea (cm)";
            // 
            // txtVarsta
            // 
            this.txtVarsta.Location = new System.Drawing.Point(132, 47);
            this.txtVarsta.Name = "txtVarsta";
            this.txtVarsta.Size = new System.Drawing.Size(140, 20);
            this.txtVarsta.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(47, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(60, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Varsta (ani)";
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.btnComanda);
            this.tabPage2.Controls.Add(this.txtPret);
            this.tabPage2.Controls.Add(this.label7);
            this.tabPage2.Controls.Add(this.txtTotalk);
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.txtNecesar);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.dgw);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(791, 426);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Comanda";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // btnComanda
            // 
            this.btnComanda.Location = new System.Drawing.Point(353, 320);
            this.btnComanda.Name = "btnComanda";
            this.btnComanda.Size = new System.Drawing.Size(104, 33);
            this.btnComanda.TabIndex = 7;
            this.btnComanda.Text = "Comanda";
            this.btnComanda.UseVisualStyleBackColor = true;
            this.btnComanda.Click += new System.EventHandler(this.btnComanda_Click);
            // 
            // txtPret
            // 
            this.txtPret.Location = new System.Drawing.Point(135, 367);
            this.txtPret.Name = "txtPret";
            this.txtPret.ReadOnly = true;
            this.txtPret.Size = new System.Drawing.Size(100, 20);
            this.txtPret.TabIndex = 6;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(56, 370);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 13);
            this.label7.TabIndex = 5;
            this.label7.Text = "Pret Total";
            // 
            // txtTotalk
            // 
            this.txtTotalk.Location = new System.Drawing.Point(135, 302);
            this.txtTotalk.Name = "txtTotalk";
            this.txtTotalk.ReadOnly = true;
            this.txtTotalk.Size = new System.Drawing.Size(100, 20);
            this.txtTotalk.TabIndex = 4;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(56, 305);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 3;
            this.label6.Text = "Total kcal";
            // 
            // txtNecesar
            // 
            this.txtNecesar.Location = new System.Drawing.Point(135, 258);
            this.txtNecesar.Name = "txtNecesar";
            this.txtNecesar.ReadOnly = true;
            this.txtNecesar.Size = new System.Drawing.Size(100, 20);
            this.txtNecesar.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(56, 261);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(73, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "Necesar zilnic";
            // 
            // dgw
            // 
            this.dgw.AutoGenerateColumns = false;
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idprodusDataGridViewTextBoxColumn,
            this.denumireprodusDataGridViewTextBoxColumn,
            this.descriereDataGridViewTextBoxColumn,
            this.pretDataGridViewTextBoxColumn,
            this.kcalDataGridViewTextBoxColumn,
            this.felulDataGridViewTextBoxColumn});
            this.dgw.DataSource = this.meniuBindingSource;
            this.dgw.Location = new System.Drawing.Point(0, 3);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(791, 233);
            this.dgw.TabIndex = 0;
            // 
            // idprodusDataGridViewTextBoxColumn
            // 
            this.idprodusDataGridViewTextBoxColumn.DataPropertyName = "id_produs";
            this.idprodusDataGridViewTextBoxColumn.HeaderText = "id_produs";
            this.idprodusDataGridViewTextBoxColumn.Name = "idprodusDataGridViewTextBoxColumn";
            // 
            // denumireprodusDataGridViewTextBoxColumn
            // 
            this.denumireprodusDataGridViewTextBoxColumn.DataPropertyName = "denumire_produs";
            this.denumireprodusDataGridViewTextBoxColumn.HeaderText = "denumire_produs";
            this.denumireprodusDataGridViewTextBoxColumn.Name = "denumireprodusDataGridViewTextBoxColumn";
            // 
            // descriereDataGridViewTextBoxColumn
            // 
            this.descriereDataGridViewTextBoxColumn.DataPropertyName = "descriere";
            this.descriereDataGridViewTextBoxColumn.HeaderText = "descriere";
            this.descriereDataGridViewTextBoxColumn.Name = "descriereDataGridViewTextBoxColumn";
            // 
            // pretDataGridViewTextBoxColumn
            // 
            this.pretDataGridViewTextBoxColumn.DataPropertyName = "pret";
            this.pretDataGridViewTextBoxColumn.HeaderText = "pret";
            this.pretDataGridViewTextBoxColumn.Name = "pretDataGridViewTextBoxColumn";
            // 
            // kcalDataGridViewTextBoxColumn
            // 
            this.kcalDataGridViewTextBoxColumn.DataPropertyName = "kcal";
            this.kcalDataGridViewTextBoxColumn.HeaderText = "kcal";
            this.kcalDataGridViewTextBoxColumn.Name = "kcalDataGridViewTextBoxColumn";
            // 
            // felulDataGridViewTextBoxColumn
            // 
            this.felulDataGridViewTextBoxColumn.DataPropertyName = "felul";
            this.felulDataGridViewTextBoxColumn.HeaderText = "felul";
            this.felulDataGridViewTextBoxColumn.Name = "felulDataGridViewTextBoxColumn";
            // 
            // meniuBindingSource
            // 
            this.meniuBindingSource.DataMember = "Meniu";
            this.meniuBindingSource.DataSource = this.gOOD_FOODDataSet;
            // 
            // gOOD_FOODDataSet
            // 
            this.gOOD_FOODDataSet.DataSetName = "GOOD_FOODDataSet";
            this.gOOD_FOODDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.label10);
            this.tabPage3.Controls.Add(this.groupBox1);
            this.tabPage3.Controls.Add(this.dgwMeniuri);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(791, 426);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Generare meniu";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(3, 212);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(211, 18);
            this.label10.TabIndex = 2;
            this.label10.Text = "Meniuril optime pentru dvs:";
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.groupBox1.Controls.Add(this.btnGenereazaMeniuri);
            this.groupBox1.Controls.Add(this.txtBuget);
            this.groupBox1.Controls.Add(this.label9);
            this.groupBox1.Controls.Add(this.txtKcalZilnice);
            this.groupBox1.Controls.Add(this.label8);
            this.groupBox1.Location = new System.Drawing.Point(3, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(788, 119);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            // 
            // btnGenereazaMeniuri
            // 
            this.btnGenereazaMeniuri.Location = new System.Drawing.Point(144, 79);
            this.btnGenereazaMeniuri.Name = "btnGenereazaMeniuri";
            this.btnGenereazaMeniuri.Size = new System.Drawing.Size(75, 23);
            this.btnGenereazaMeniuri.TabIndex = 4;
            this.btnGenereazaMeniuri.Text = "Genereaza";
            this.btnGenereazaMeniuri.UseVisualStyleBackColor = true;
            this.btnGenereazaMeniuri.Click += new System.EventHandler(this.btnGenereazaMeniuri_Click);
            // 
            // txtBuget
            // 
            this.txtBuget.Location = new System.Drawing.Point(131, 53);
            this.txtBuget.Name = "txtBuget";
            this.txtBuget.Size = new System.Drawing.Size(100, 20);
            this.txtBuget.TabIndex = 3;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 56);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(35, 13);
            this.label9.TabIndex = 2;
            this.label9.Text = "Buget";
            // 
            // txtKcalZilnice
            // 
            this.txtKcalZilnice.Location = new System.Drawing.Point(131, 13);
            this.txtKcalZilnice.Name = "txtKcalZilnice";
            this.txtKcalZilnice.ReadOnly = true;
            this.txtKcalZilnice.Size = new System.Drawing.Size(100, 20);
            this.txtKcalZilnice.TabIndex = 1;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(6, 16);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(119, 13);
            this.label8.TabIndex = 0;
            this.label8.Text = "Necesarul zilnic de kcal";
            // 
            // dgwMeniuri
            // 
            this.dgwMeniuri.AllowUserToAddRows = false;
            this.dgwMeniuri.AllowUserToDeleteRows = false;
            this.dgwMeniuri.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgwMeniuri.Location = new System.Drawing.Point(0, 233);
            this.dgwMeniuri.Name = "dgwMeniuri";
            this.dgwMeniuri.ReadOnly = true;
            this.dgwMeniuri.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.AutoSizeToFirstHeader;
            this.dgwMeniuri.Size = new System.Drawing.Size(791, 193);
            this.dgwMeniuri.TabIndex = 0;
            this.dgwMeniuri.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgwMeniuri_CellClick);
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.cht);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(791, 426);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "Grafic Kcal";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // cht
            // 
            chartArea1.Name = "ChartArea1";
            this.cht.ChartAreas.Add(chartArea1);
            this.cht.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.cht.Location = new System.Drawing.Point(59, 47);
            this.cht.Name = "cht";
            series1.ChartArea = "ChartArea1";
            series1.Name = "Series1";
            this.cht.Series.Add(series1);
            this.cht.Size = new System.Drawing.Size(668, 300);
            this.cht.TabIndex = 0;
            this.cht.Text = "chart1";
            // 
            // meniuTableAdapter
            // 
            this.meniuTableAdapter.ClearBeforeFill = true;
            // 
            // Optiuni
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.Name = "Optiuni";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Optiuni";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.meniuBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gOOD_FOODDataSet)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgwMeniuri)).EndInit();
            this.tabPage4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.cht)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.TableLayoutPanel tlp;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnGen;
        private System.Windows.Forms.TextBox txtGreutate;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtInaltime;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtVarsta;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.Button btnComanda;
        private System.Windows.Forms.TextBox txtPret;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtTotalk;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtNecesar;
        private System.Windows.Forms.Label label5;
        private GOOD_FOODDataSet gOOD_FOODDataSet;
        private System.Windows.Forms.BindingSource meniuBindingSource;
        private GOOD_FOODDataSetTableAdapters.MeniuTableAdapter meniuTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idprodusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn denumireprodusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn descriereDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn pretDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn kcalDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn felulDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataVisualization.Charting.Chart cht;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnGenereazaMeniuri;
        private System.Windows.Forms.TextBox txtBuget;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txtKcalZilnice;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.DataGridView dgwMeniuri;
    }
}