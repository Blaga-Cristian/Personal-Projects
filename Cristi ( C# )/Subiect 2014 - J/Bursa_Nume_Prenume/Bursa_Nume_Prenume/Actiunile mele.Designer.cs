namespace Bursa_Nume_Prenume
{
    partial class Actiunile_mele
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
            this.dgw = new System.Windows.Forms.DataGridView();
            this.Denumire = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Numar_actiuni = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Valoare_actiune_initial = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Valoare_actiune_momentana = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Valoarea_cu_care_sa_modificat = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Total_valoare_inital = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Total_valoare_momentana = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ProfitPierdere_momentara = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ProfitPierdere_total = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.txtProfit = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            this.SuspendLayout();
            // 
            // dgw
            // 
            this.dgw.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Denumire,
            this.Numar_actiuni,
            this.Valoare_actiune_initial,
            this.Valoare_actiune_momentana,
            this.Valoarea_cu_care_sa_modificat,
            this.Total_valoare_inital,
            this.Total_valoare_momentana,
            this.ProfitPierdere_momentara,
            this.ProfitPierdere_total});
            this.dgw.Location = new System.Drawing.Point(1, 0);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(799, 315);
            this.dgw.TabIndex = 0;
            // 
            // Denumire
            // 
            this.Denumire.HeaderText = "Denumire";
            this.Denumire.Name = "Denumire";
            // 
            // Numar_actiuni
            // 
            this.Numar_actiuni.HeaderText = "Numar actiuni";
            this.Numar_actiuni.Name = "Numar_actiuni";
            // 
            // Valoare_actiune_initial
            // 
            this.Valoare_actiune_initial.HeaderText = "Valoare actiune initial";
            this.Valoare_actiune_initial.Name = "Valoare_actiune_initial";
            // 
            // Valoare_actiune_momentana
            // 
            this.Valoare_actiune_momentana.HeaderText = "Valoare actiune momentana";
            this.Valoare_actiune_momentana.Name = "Valoare_actiune_momentana";
            // 
            // Valoarea_cu_care_sa_modificat
            // 
            this.Valoarea_cu_care_sa_modificat.HeaderText = "Valoarea cu care sa modificat";
            this.Valoarea_cu_care_sa_modificat.Name = "Valoarea_cu_care_sa_modificat";
            // 
            // Total_valoare_inital
            // 
            this.Total_valoare_inital.HeaderText = "Tota valoare inital";
            this.Total_valoare_inital.Name = "Total_valoare_inital";
            // 
            // Total_valoare_momentana
            // 
            this.Total_valoare_momentana.HeaderText = "Total valoare momentana";
            this.Total_valoare_momentana.Name = "Total_valoare_momentana";
            // 
            // ProfitPierdere_momentara
            // 
            this.ProfitPierdere_momentara.HeaderText = "ProfitPierdere momentara";
            this.ProfitPierdere_momentara.Name = "ProfitPierdere_momentara";
            // 
            // ProfitPierdere_total
            // 
            this.ProfitPierdere_total.HeaderText = "ProfitPierdere_total";
            this.ProfitPierdere_total.Name = "ProfitPierdere_total";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(218, 350);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(129, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Profit pierdere total";
            // 
            // txtProfit
            // 
            this.txtProfit.Location = new System.Drawing.Point(369, 350);
            this.txtProfit.Name = "txtProfit";
            this.txtProfit.ReadOnly = true;
            this.txtProfit.Size = new System.Drawing.Size(151, 20);
            this.txtProfit.TabIndex = 2;
            // 
            // Actiunile_mele
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 381);
            this.Controls.Add(this.txtProfit);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dgw);
            this.Name = "Actiunile_mele";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Actiunile_mele";
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtProfit;
        private System.Windows.Forms.DataGridViewTextBoxColumn Denumire;
        private System.Windows.Forms.DataGridViewTextBoxColumn Numar_actiuni;
        private System.Windows.Forms.DataGridViewTextBoxColumn Valoare_actiune_initial;
        private System.Windows.Forms.DataGridViewTextBoxColumn Valoare_actiune_momentana;
        private System.Windows.Forms.DataGridViewTextBoxColumn Valoarea_cu_care_sa_modificat;
        private System.Windows.Forms.DataGridViewTextBoxColumn Total_valoare_inital;
        private System.Windows.Forms.DataGridViewTextBoxColumn Total_valoare_momentana;
        private System.Windows.Forms.DataGridViewTextBoxColumn ProfitPierdere_momentara;
        private System.Windows.Forms.DataGridViewTextBoxColumn ProfitPierdere_total;
    }
}