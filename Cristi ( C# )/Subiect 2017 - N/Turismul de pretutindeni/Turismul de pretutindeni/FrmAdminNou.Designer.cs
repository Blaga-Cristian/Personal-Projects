namespace Turismul_de_pretutindeni
{
    partial class FrmAdminNou
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
            this.label1 = new System.Windows.Forms.Label();
            this.cmb = new System.Windows.Forms.ComboBox();
            this.btnRenunta = new System.Windows.Forms.Button();
            this.btnInregistreaza = new System.Windows.Forms.Button();
            this.btnAdmin = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(30, 71);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "User:";
            // 
            // cmb
            // 
            this.cmb.FormattingEnabled = true;
            this.cmb.Location = new System.Drawing.Point(96, 68);
            this.cmb.Name = "cmb";
            this.cmb.Size = new System.Drawing.Size(218, 21);
            this.cmb.TabIndex = 1;
            // 
            // btnRenunta
            // 
            this.btnRenunta.Location = new System.Drawing.Point(12, 143);
            this.btnRenunta.Name = "btnRenunta";
            this.btnRenunta.Size = new System.Drawing.Size(78, 22);
            this.btnRenunta.TabIndex = 2;
            this.btnRenunta.Text = "Renunta";
            this.btnRenunta.UseVisualStyleBackColor = true;
            this.btnRenunta.Click += new System.EventHandler(this.btnRenunta_Click);
            // 
            // btnInregistreaza
            // 
            this.btnInregistreaza.Location = new System.Drawing.Point(129, 143);
            this.btnInregistreaza.Name = "btnInregistreaza";
            this.btnInregistreaza.Size = new System.Drawing.Size(78, 22);
            this.btnInregistreaza.TabIndex = 3;
            this.btnInregistreaza.Text = "Inregistreaza";
            this.btnInregistreaza.UseVisualStyleBackColor = true;
            this.btnInregistreaza.Click += new System.EventHandler(this.btnInregistreaza_Click);
            // 
            // btnAdmin
            // 
            this.btnAdmin.Location = new System.Drawing.Point(227, 143);
            this.btnAdmin.Name = "btnAdmin";
            this.btnAdmin.Size = new System.Drawing.Size(113, 22);
            this.btnAdmin.TabIndex = 4;
            this.btnAdmin.Text = "Transforma in admin";
            this.btnAdmin.UseVisualStyleBackColor = true;
            this.btnAdmin.Click += new System.EventHandler(this.btnAdmin_Click);
            // 
            // FrmAdminNou
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(338, 177);
            this.Controls.Add(this.btnAdmin);
            this.Controls.Add(this.btnInregistreaza);
            this.Controls.Add(this.btnRenunta);
            this.Controls.Add(this.cmb);
            this.Controls.Add(this.label1);
            this.Name = "FrmAdminNou";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FrmAdminNou";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cmb;
        private System.Windows.Forms.Button btnRenunta;
        private System.Windows.Forms.Button btnInregistreaza;
        private System.Windows.Forms.Button btnAdmin;
    }
}