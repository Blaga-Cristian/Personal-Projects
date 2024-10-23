using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Scroll_text
{
    public partial class Form1 : Form
    {

        float textheight;
        float lineheight;
        float clientlines;
        float size = 14;
        Font font = new Font("Times New Roman", 12);
        int linesbacked = 0;

        string s = "în câmpia Dunării, cu câţiva ani înaintea celui de-al doilea război mondial, se Bai£jcJ* Cîmpul avea cu oamenii nesfârşită răbdare; viaţa se scurgea aici fără conflicte mari. Era începutul verii. Familia Moromete se întorsese mai devreme de la câmp. Cât ajunseseră acasă, Paraschi, cel mai mare dintre co,pij»jse dăduse jos din căruţă, lăsase pe alţii să deshame şi să dea jos uneltele, iar el întinsese pe prispă o haină veche şi se culcase peste ea gemând. La fel făcuse şi al doilea fiu, Nilă; intrase în casă şi după ce se aruncase întrun pat, începuse şi el să geamă, dar mai tare ca fratele său, ca şi când ar fi fost bolnav. Al treilea băiat, Achim, se furişase în grajdul cailor, se trântise în iesle să nu-l mai găsească nimeni, iar cele două fete, Tita şi Ilinca, plecaseră repede la gârlă să se scalde. Rămas singur în mijlocul bătăturii, Moromete, tatăl, trăsese căruţa sub Umbra mare a celor doi salcâmi de lângă poarta grădinii şi apoi ieşise şi el la drum cu ţigarea în gură. Părea de la sine înţeles că singură mama rămânea să aibă grijă ca ziua să se sfârşească bine... Moromete stătea pe stănoaga podiştei şi se uita peste drum. Stătea degeaba, nu se uita în mod deosebit, dar pe faţa lui se vedea că n-ar fi r$u dacă s-ar ivi cineva... Oamenii însă aveau treabă prin curţi, nu era  timpul de ieşit în drum. Din mâna lui fumul ţigării se ridica drept  JMMiiăĂ    în- Ce mai faci, Moromete? Ai terminat, mă, de sapă? Iată că se ivise totuşi cineva. Moromete ridică fruntea şi îl văzu pe jfecinul său din spatele casei apropiindu-se de podişcă. Se uită numat o dată la el, apoi începu să se uite în altă parte; se vedea că nu o astfel de apariţie aştepta. „...Pe mă-ta şi pe tine, chiorule!\" şopti atunci Moromete pentru el însuşi, ca şi când până atunci ar mai fi înjurat pe cineva în gând 7 şi acum îl îngloba şi pe vecin, fiindcă tot apăruse; după care răspunsese foarte binevoitor:- Da, am terminat... Tu mai ai, mă, Bălosule? —  Am- terminat şi eu. Mai aveam un petic dincoace în Pământuri, mi l-au săpat ai lui Ţugurlan... Ce faci, Moromete, te-ai mai gândit? îmi dai salcâmu ăla? Moromete se uită ţintă la vecinul său înţelegând pentru ce ieşise el la drum şi nu răspunse la întrebare. „Da, am discutat odată să-ţi vând un salcâm! Poate am să ţi-l vând... poate n-o să ţi-l vând... De ce trebuie să ne grăbim aşa!?\" părea el să-i spună.- Dar Victor al tău... El nu mai iese la sapă, Bălosule? Sau de când este voiajor nu-l mai aranjează? zise Moromete. Adică... admitem cazul că fiind ocupat... mai adăugă el. Vecinul avu bănuiala că aceste cuvinte nu sunt chiar atât de nevinovate cum s-ar fi putut înţelege din glasul cu care fuseseră rostite, dar trecu dlpfc ca şi când n-ar fi înţeles ce se întâmpla, apoi deodată repezi calului cu pată puterea un picior în burtă. Tot atunci mama ieşi în prag. Avea faţa roşie şi obosită, iar năduşeala Tgea în şiroaie înnegrite peste obraji şi gât. Ilie, unde s-au dus fetele alea? Ce fac eu aici singură? Acu se ericeşte şi ce mâncaţi? Raci o să mâncăm, fa, d-aia te vaiţi tu? răspunse Moromete trăgând spre grajd. iaci nu se găseau nicăieri în apele satului. Tocmai raci, prin urmare, tu să mănânce la masă. Femeia se şterse cu deznădejde pe frunte, iţi în sec şi pieri în tindă. Vn în hiţi în sec şi pien in unu». L Niculae, unde eşti, mă? strigă Moromote spre grădină.- Aicea sunt! se auzi un glas deundeva.- Aicea sunt! se auzi un glas aeunaeva.- Ce faci acolo? Treci încoace şi ajută-i mă-tii! Te duseşi în grădină sa te odihneşti, că până acum stătuşi! Când ţi-oi da una după ceafă, îţi sat mucii pe jos! | Pe poarta grădinii intră un băiat de vreo doisprezece ani. Avea capul o <-- «-nlatri săi    8°l 5* cămaşa de pe el era ferfeniţă. Picioarele goale erau pline de zgârieturi ■1 mai dai, Moromete? Ca vroiam    I    ^ cu urme de ^^ închegat cu praf- Treci la mă-ta şi vezi ce treabă are! spuse iar Moromete, pornind încet spre grădină. peste asta.- Păi de ce zici că nu vreai să mi ţi-l plătesc... Drept răspuns, Moromete începu să se uite pe cer. '\"\"t    - Să ţii minte că la noapte o să plouă. Dacă dă ploaia asta, o să fa< o grămadă de grâu, Tudore! zise el. Bălosu nu mai zise nici el nimic; apoi după câteva clipe schimbă vorbî - Mă întâlnii pe la prânz cu Jupuitu. Zicea că mâine dimineaţa1! porneşte prin sat după fonciire. Moromete rămase nemişcat. —>    - Zice că a primit o dispoziţie, sau un ordin, dracu să-l ia... Că are de achitat fonciire şi n-o s-o achite mâine, o să le ia din casă. Moromete se mohorî dintr-o dată. Vru să răspundă, dar se ridică neaşteptate de pe stanoagă şi sări spre poartă; un cal scăpase din gr şi vroia să iasă la drum.- Nea îndărăt, blegule, unde vreai să te duci? strigă omul închizând poarta în nas. Calul nu se sperie însă, rămase cu botul lângă ulucă şi suflă puteri pe nări, apoi, cu dispreţ parcă, se întoarse cu sp";
        
        public Form1()
        {
            InitializeComponent();
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer |
                ControlStyles.UserPaint | ControlStyles.AllPaintingInWmPaint, true);

            Graphics g = this.CreateGraphics();
            textheight = g.MeasureString(s, font, ClientRectangle.Width).Height;
            float x = g.MeasureString("A", font, ClientRectangle.Width).Height;
            lineheight = font.GetHeight(g);
            clientlines = ClientRectangle.Height / lineheight;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawString(s, font, Brushes.Black, new RectangleF(0, -linesbacked * lineheight, ClientRectangle.Width, 0));
        }

        protected override void OnMouseWheel(MouseEventArgs mea)
        {
            int lscroll = mea.Delta * SystemInformation.MouseWheelScrollLines / SystemInformation.MouseWheelScrollDelta;

            linesbacked -= lscroll;

            linesbacked = (int)Math.Max(0, Math.Min(linesbacked, 1 + (textheight - ClientRectangle.Height) / lineheight));

            this.Invalidate();
        }
    }
}
