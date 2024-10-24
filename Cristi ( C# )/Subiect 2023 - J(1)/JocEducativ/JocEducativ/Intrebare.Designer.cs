namespace JocEducativ
{
    partial class Intrebare
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
            this.rtb = new System.Windows.Forms.RichTextBox();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.rb3 = new System.Windows.Forms.RadioButton();
            this.btnAns = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // rtb
            // 
            this.rtb.Location = new System.Drawing.Point(26, 12);
            this.rtb.Name = "rtb";
            this.rtb.ReadOnly = true;
            this.rtb.Size = new System.Drawing.Size(403, 112);
            this.rtb.TabIndex = 0;
            this.rtb.Text = "";
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Location = new System.Drawing.Point(29, 162);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(85, 17);
            this.rb1.TabIndex = 1;
            this.rb1.TabStop = true;
            this.rb1.Text = "radioButton1";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Location = new System.Drawing.Point(29, 188);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(85, 17);
            this.rb2.TabIndex = 2;
            this.rb2.TabStop = true;
            this.rb2.Text = "radioButton2";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // rb3
            // 
            this.rb3.AutoSize = true;
            this.rb3.Location = new System.Drawing.Point(29, 211);
            this.rb3.Name = "rb3";
            this.rb3.Size = new System.Drawing.Size(85, 17);
            this.rb3.TabIndex = 3;
            this.rb3.TabStop = true;
            this.rb3.Text = "radioButton3";
            this.rb3.UseVisualStyleBackColor = true;
            // 
            // btnAns
            // 
            this.btnAns.Location = new System.Drawing.Point(224, 202);
            this.btnAns.Name = "btnAns";
            this.btnAns.Size = new System.Drawing.Size(134, 34);
            this.btnAns.TabIndex = 4;
            this.btnAns.Text = "Inregistreaza Raspuns";
            this.btnAns.UseVisualStyleBackColor = true;
            this.btnAns.Click += new System.EventHandler(this.btnAns_Click);
            // 
            // Intrebare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(462, 264);
            this.Controls.Add(this.btnAns);
            this.Controls.Add(this.rb3);
            this.Controls.Add(this.rb2);
            this.Controls.Add(this.rb1);
            this.Controls.Add(this.rtb);
            this.Name = "Intrebare";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Intrebare";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtb;
        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.RadioButton rb3;
        private System.Windows.Forms.Button btnAns;
    }
}