namespace PollutionMap
{
    partial class AdaugaMasurareForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdaugaMasurareForm));
            this.txtAdMas = new System.Windows.Forms.TextBox();
            this.btnAdMas = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtAdMas
            // 
            this.txtAdMas.Location = new System.Drawing.Point(32, 22);
            this.txtAdMas.Name = "txtAdMas";
            this.txtAdMas.Size = new System.Drawing.Size(271, 20);
            this.txtAdMas.TabIndex = 0;
            // 
            // btnAdMas
            // 
            this.btnAdMas.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAdMas.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.btnAdMas.Location = new System.Drawing.Point(32, 98);
            this.btnAdMas.Name = "btnAdMas";
            this.btnAdMas.Size = new System.Drawing.Size(271, 37);
            this.btnAdMas.TabIndex = 1;
            this.btnAdMas.Text = "Adauga masurare";
            this.btnAdMas.UseVisualStyleBackColor = true;
            this.btnAdMas.Click += new System.EventHandler(this.btnAdMas_Click);
            // 
            // AdaugaMasurareForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(340, 147);
            this.Controls.Add(this.btnAdMas);
            this.Controls.Add(this.txtAdMas);
            this.Name = "AdaugaMasurareForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Tag = " ";
            this.Text = "Adauga Masurare";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtAdMas;
        private System.Windows.Forms.Button btnAdMas;
    }
}