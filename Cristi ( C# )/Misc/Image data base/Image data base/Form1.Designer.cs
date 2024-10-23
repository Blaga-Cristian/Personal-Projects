namespace Image_data_base
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
            this.components = new System.ComponentModel.Container();
            this.btnAdd = new System.Windows.Forms.Button();
            this.dgw = new System.Windows.Forms.DataGridView();
            this.idDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.imagineDataGridViewImageColumn = new System.Windows.Forms.DataGridViewImageColumn();
            this.imaginiBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.imaginiDataSet = new Image_data_base.ImaginiDataSet();
            this.imaginiBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.btnSet = new System.Windows.Forms.Button();
            this.pb = new System.Windows.Forms.PictureBox();
            this.txtId = new System.Windows.Forms.TextBox();
            this.imaginiTableAdapter = new Image_data_base.ImaginiDataSetTableAdapters.ImaginiTableAdapter();
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).BeginInit();
            this.SuspendLayout();
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(12, 44);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 23);
            this.btnAdd.TabIndex = 0;
            this.btnAdd.Text = "Adauga";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // dgw
            // 
            this.dgw.AutoGenerateColumns = false;
            this.dgw.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgw.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgw.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idDataGridViewTextBoxColumn,
            this.imagineDataGridViewImageColumn});
            this.dgw.DataSource = this.imaginiBindingSource1;
            this.dgw.Location = new System.Drawing.Point(0, 173);
            this.dgw.Name = "dgw";
            this.dgw.Size = new System.Drawing.Size(802, 280);
            this.dgw.TabIndex = 1;
            // 
            // idDataGridViewTextBoxColumn
            // 
            this.idDataGridViewTextBoxColumn.DataPropertyName = "Id";
            this.idDataGridViewTextBoxColumn.HeaderText = "Id";
            this.idDataGridViewTextBoxColumn.Name = "idDataGridViewTextBoxColumn";
            this.idDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // imagineDataGridViewImageColumn
            // 
            this.imagineDataGridViewImageColumn.DataPropertyName = "Imagine";
            this.imagineDataGridViewImageColumn.HeaderText = "Imagine";
            this.imagineDataGridViewImageColumn.Name = "imagineDataGridViewImageColumn";
            // 
            // imaginiBindingSource1
            // 
            this.imaginiBindingSource1.DataMember = "Imagini";
            this.imaginiBindingSource1.DataSource = this.imaginiDataSet;
            // 
            // imaginiDataSet
            // 
            this.imaginiDataSet.DataSetName = "ImaginiDataSet";
            this.imaginiDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // imaginiBindingSource
            // 
            this.imaginiBindingSource.DataMember = "Imagini";
            // 
            // btnSet
            // 
            this.btnSet.Location = new System.Drawing.Point(168, 12);
            this.btnSet.Name = "btnSet";
            this.btnSet.Size = new System.Drawing.Size(122, 23);
            this.btnSet.TabIndex = 2;
            this.btnSet.Text = "Seteaza imagine";
            this.btnSet.UseVisualStyleBackColor = true;
            this.btnSet.Click += new System.EventHandler(this.btnSet_Click);
            // 
            // pb
            // 
            this.pb.Location = new System.Drawing.Point(296, 12);
            this.pb.Name = "pb";
            this.pb.Size = new System.Drawing.Size(135, 104);
            this.pb.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb.TabIndex = 3;
            this.pb.TabStop = false;
            // 
            // txtId
            // 
            this.txtId.Location = new System.Drawing.Point(226, 45);
            this.txtId.Name = "txtId";
            this.txtId.Size = new System.Drawing.Size(64, 20);
            this.txtId.TabIndex = 4;
            // 
            // imaginiTableAdapter
            // 
            this.imaginiTableAdapter.ClearBeforeFill = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.txtId);
            this.Controls.Add(this.pb);
            this.Controls.Add(this.btnSet);
            this.Controls.Add(this.dgw);
            this.Controls.Add(this.btnAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgw)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imaginiBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.DataGridView dgw;
        private System.Windows.Forms.BindingSource imaginiBindingSource;
        private System.Windows.Forms.Button btnSet;
        private System.Windows.Forms.PictureBox pb;
        private System.Windows.Forms.TextBox txtId;
        private ImaginiDataSet imaginiDataSet;
        private System.Windows.Forms.BindingSource imaginiBindingSource1;
        private ImaginiDataSetTableAdapters.ImaginiTableAdapter imaginiTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn idDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewImageColumn imagineDataGridViewImageColumn;
    }
}

