namespace Foreign_Key
{
    partial class Form1
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
            this.btnAdd = new System.Windows.Forms.Button();
            this.pb = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.txtNume = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCreaza = new System.Windows.Forms.Button();
            this.btnSterge = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.txtSterge = new System.Windows.Forms.TextBox();
            this.btnStergeFisier = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.txtFisier = new System.Windows.Forms.TextBox();
            this.btnCopy = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtFisierCopiaza = new System.Windows.Forms.TextBox();
            this.txtDest = new System.Windows.Forms.TextBox();
            this.txtExp = new System.Windows.Forms.TextBox();
            this.btnCheck = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(625, 37);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(119, 46);
            this.btnAdd.TabIndex = 0;
            this.btnAdd.Text = "Adauga Imagine";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(582, 175);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(206, 122);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 1;
            this.pb.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(625, 89);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(103, 44);
            this.button1.TabIndex = 2;
            this.button1.Text = "Imagine";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // txtNume
            // 
            this.txtNume.Location = new System.Drawing.Point(91, 22);
            this.txtNume.Name = "txtNume";
            this.txtNume.Size = new System.Drawing.Size(100, 20);
            this.txtNume.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Nume director:";
            // 
            // btnCreaza
            // 
            this.btnCreaza.Location = new System.Drawing.Point(207, 19);
            this.btnCreaza.Name = "btnCreaza";
            this.btnCreaza.Size = new System.Drawing.Size(75, 23);
            this.btnCreaza.TabIndex = 5;
            this.btnCreaza.Text = "Creaza";
            this.btnCreaza.UseVisualStyleBackColor = true;
            this.btnCreaza.Click += new System.EventHandler(this.btnCreaza_Click);
            // 
            // btnSterge
            // 
            this.btnSterge.Location = new System.Drawing.Point(207, 60);
            this.btnSterge.Name = "btnSterge";
            this.btnSterge.Size = new System.Drawing.Size(75, 23);
            this.btnSterge.TabIndex = 8;
            this.btnSterge.Text = "Sterge";
            this.btnSterge.UseVisualStyleBackColor = true;
            this.btnSterge.Click += new System.EventHandler(this.btnSterge_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 66);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(76, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Nume director:";
            // 
            // txtSterge
            // 
            this.txtSterge.Location = new System.Drawing.Point(91, 63);
            this.txtSterge.Name = "txtSterge";
            this.txtSterge.Size = new System.Drawing.Size(100, 20);
            this.txtSterge.TabIndex = 6;
            // 
            // btnStergeFisier
            // 
            this.btnStergeFisier.Location = new System.Drawing.Point(207, 110);
            this.btnStergeFisier.Name = "btnStergeFisier";
            this.btnStergeFisier.Size = new System.Drawing.Size(75, 23);
            this.btnStergeFisier.TabIndex = 11;
            this.btnStergeFisier.Text = "Sterge";
            this.btnStergeFisier.UseVisualStyleBackColor = true;
            this.btnStergeFisier.Click += new System.EventHandler(this.btnStergeFisier_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 116);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(62, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "Nume fisier:";
            // 
            // txtFisier
            // 
            this.txtFisier.Location = new System.Drawing.Point(91, 113);
            this.txtFisier.Name = "txtFisier";
            this.txtFisier.Size = new System.Drawing.Size(100, 20);
            this.txtFisier.TabIndex = 9;
            // 
            // btnCopy
            // 
            this.btnCopy.Location = new System.Drawing.Point(207, 146);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(75, 23);
            this.btnCopy.TabIndex = 14;
            this.btnCopy.Text = "Copiaza";
            this.btnCopy.UseVisualStyleBackColor = true;
            this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 152);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(62, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Nume fisier:";
            // 
            // txtFisierCopiaza
            // 
            this.txtFisierCopiaza.Location = new System.Drawing.Point(91, 149);
            this.txtFisierCopiaza.Name = "txtFisierCopiaza";
            this.txtFisierCopiaza.Size = new System.Drawing.Size(100, 20);
            this.txtFisierCopiaza.TabIndex = 12;
            // 
            // txtDest
            // 
            this.txtDest.Location = new System.Drawing.Point(91, 175);
            this.txtDest.Name = "txtDest";
            this.txtDest.Size = new System.Drawing.Size(100, 20);
            this.txtDest.TabIndex = 15;
            // 
            // txtExp
            // 
            this.txtExp.Location = new System.Drawing.Point(81, 231);
            this.txtExp.Name = "txtExp";
            this.txtExp.Size = new System.Drawing.Size(85, 20);
            this.txtExp.TabIndex = 16;
            // 
            // btnCheck
            // 
            this.btnCheck.Location = new System.Drawing.Point(172, 229);
            this.btnCheck.Name = "btnCheck";
            this.btnCheck.Size = new System.Drawing.Size(75, 23);
            this.btnCheck.TabIndex = 17;
            this.btnCheck.Text = "Check ";
            this.btnCheck.UseVisualStyleBackColor = true;
            this.btnCheck.Click += new System.EventHandler(this.btnCheck_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnCheck);
            this.Controls.Add(this.txtExp);
            this.Controls.Add(this.txtDest);
            this.Controls.Add(this.btnCopy);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtFisierCopiaza);
            this.Controls.Add(this.btnStergeFisier);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtFisier);
            this.Controls.Add(this.btnSterge);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtSterge);
            this.Controls.Add(this.btnCreaza);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtNume);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.btnAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox txtNume;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCreaza;
        private System.Windows.Forms.Button btnSterge;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtSterge;
        private System.Windows.Forms.Button btnStergeFisier;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtFisier;
        private System.Windows.Forms.Button btnCopy;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtFisierCopiaza;
        private System.Windows.Forms.TextBox txtDest;
        private System.Windows.Forms.TextBox txtExp;
        private System.Windows.Forms.Button btnCheck;
    }
}

