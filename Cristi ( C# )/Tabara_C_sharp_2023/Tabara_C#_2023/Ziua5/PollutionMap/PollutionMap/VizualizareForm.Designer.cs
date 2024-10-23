namespace PollutionMap
{
    partial class VizualizareForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(VizualizareForm));
            this.tabCtrl = new System.Windows.Forms.TabControl();
            this.tabHarta = new System.Windows.Forms.TabPage();
            this.tabTraseu = new System.Windows.Forms.TabPage();
            this.lblUtiliz = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cmbHarta = new System.Windows.Forms.ComboBox();
            this.dtpDataMas = new System.Windows.Forms.DateTimePicker();
            this.label3 = new System.Windows.Forms.Label();
            this.cmbFiltru = new System.Windows.Forms.ComboBox();
            this.btnResetFiltru = new System.Windows.Forms.Button();
            this.pbHarta = new System.Windows.Forms.PictureBox();
            this.tabCtrl.SuspendLayout();
            this.tabHarta.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbHarta)).BeginInit();
            this.SuspendLayout();
            // 
            // tabCtrl
            // 
            this.tabCtrl.Controls.Add(this.tabHarta);
            this.tabCtrl.Controls.Add(this.tabTraseu);
            this.tabCtrl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabCtrl.Location = new System.Drawing.Point(0, 0);
            this.tabCtrl.Name = "tabCtrl";
            this.tabCtrl.SelectedIndex = 0;
            this.tabCtrl.Size = new System.Drawing.Size(932, 518);
            this.tabCtrl.TabIndex = 0;
            // 
            // tabHarta
            // 
            this.tabHarta.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("tabHarta.BackgroundImage")));
            this.tabHarta.Controls.Add(this.pbHarta);
            this.tabHarta.Controls.Add(this.btnResetFiltru);
            this.tabHarta.Controls.Add(this.cmbFiltru);
            this.tabHarta.Controls.Add(this.label3);
            this.tabHarta.Controls.Add(this.dtpDataMas);
            this.tabHarta.Controls.Add(this.cmbHarta);
            this.tabHarta.Controls.Add(this.label2);
            this.tabHarta.Controls.Add(this.label1);
            this.tabHarta.Controls.Add(this.lblUtiliz);
            this.tabHarta.Location = new System.Drawing.Point(4, 22);
            this.tabHarta.Name = "tabHarta";
            this.tabHarta.Padding = new System.Windows.Forms.Padding(3);
            this.tabHarta.Size = new System.Drawing.Size(924, 492);
            this.tabHarta.TabIndex = 0;
            this.tabHarta.Text = "Harta";
            this.tabHarta.UseVisualStyleBackColor = true;
            // 
            // tabTraseu
            // 
            this.tabTraseu.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("tabTraseu.BackgroundImage")));
            this.tabTraseu.Location = new System.Drawing.Point(4, 22);
            this.tabTraseu.Name = "tabTraseu";
            this.tabTraseu.Padding = new System.Windows.Forms.Padding(3);
            this.tabTraseu.Size = new System.Drawing.Size(792, 424);
            this.tabTraseu.TabIndex = 1;
            this.tabTraseu.Text = "Traseu";
            this.tabTraseu.UseVisualStyleBackColor = true;
            // 
            // lblUtiliz
            // 
            this.lblUtiliz.AutoSize = true;
            this.lblUtiliz.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblUtiliz.Location = new System.Drawing.Point(8, 28);
            this.lblUtiliz.Name = "lblUtiliz";
            this.lblUtiliz.Size = new System.Drawing.Size(78, 17);
            this.lblUtiliz.TabIndex = 0;
            this.lblUtiliz.Text = "Utilizator:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 63);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(33, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Harta";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 125);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Data";
            // 
            // cmbHarta
            // 
            this.cmbHarta.FormattingEnabled = true;
            this.cmbHarta.Location = new System.Drawing.Point(28, 79);
            this.cmbHarta.Name = "cmbHarta";
            this.cmbHarta.Size = new System.Drawing.Size(200, 21);
            this.cmbHarta.TabIndex = 3;
            // 
            // dtpDataMas
            // 
            this.dtpDataMas.Location = new System.Drawing.Point(28, 141);
            this.dtpDataMas.Name = "dtpDataMas";
            this.dtpDataMas.Size = new System.Drawing.Size(200, 20);
            this.dtpDataMas.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(28, 228);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Filtru";
            // 
            // cmbFiltru
            // 
            this.cmbFiltru.FormattingEnabled = true;
            this.cmbFiltru.Location = new System.Drawing.Point(31, 244);
            this.cmbFiltru.Name = "cmbFiltru";
            this.cmbFiltru.Size = new System.Drawing.Size(197, 21);
            this.cmbFiltru.TabIndex = 6;
            // 
            // btnResetFiltru
            // 
            this.btnResetFiltru.Location = new System.Drawing.Point(114, 284);
            this.btnResetFiltru.Name = "btnResetFiltru";
            this.btnResetFiltru.Size = new System.Drawing.Size(114, 40);
            this.btnResetFiltru.TabIndex = 7;
            this.btnResetFiltru.Text = "Reseteaza Filtru";
            this.btnResetFiltru.UseVisualStyleBackColor = true;
            // 
            // pbHarta
            // 
            this.pbHarta.Location = new System.Drawing.Point(279, 7);
            this.pbHarta.Name = "pbHarta";
            this.pbHarta.Size = new System.Drawing.Size(640, 480);
            this.pbHarta.TabIndex = 8;
            this.pbHarta.TabStop = false;
            // 
            // VizualizareForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(932, 518);
            this.Controls.Add(this.tabCtrl);
            this.Name = "VizualizareForm";
            this.Text = "VizualizareForm";
            this.tabCtrl.ResumeLayout(false);
            this.tabHarta.ResumeLayout(false);
            this.tabHarta.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbHarta)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabCtrl;
        private System.Windows.Forms.TabPage tabHarta;
        private System.Windows.Forms.TabPage tabTraseu;
        private System.Windows.Forms.PictureBox pbHarta;
        private System.Windows.Forms.Button btnResetFiltru;
        private System.Windows.Forms.ComboBox cmbFiltru;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DateTimePicker dtpDataMas;
        private System.Windows.Forms.ComboBox cmbHarta;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblUtiliz;
    }
}