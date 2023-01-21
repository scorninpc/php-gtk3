<?php

/**
 * Example of css styling
 */

Gtk::init();

// Classe de testes
class Teste
{
	// Vetor que armazena todos os widgets da interface
	public $widgets = array();
	
	// Construtor da classe
	public function __construct()
	{	
		// Cria o container
		$this->widgets['fixTeste'] = new GtkFixed();
		
		// Cria a janela
		$this->widgets['frmTeste'] = new GtkWindow();
		$this->widgets['frmTeste']->set_size_request(200, 200);
		
		// Cria o eventbox
		$this->widgets['evtTeste'] = new GtkButton();
		$this->widgets['evtTeste']->set_size_request(100, 50);
		$this->widgets['evtTeste']->set_name("eventb");
		$this->widgets['fixTeste']->put($this->widgets['evtTeste'], 8, 8);
		
		$context = $this->widgets['evtTeste']->get_style_context();
		$context->add_class("eventbox");
		
		// Mostra a janela
		$this->widgets['frmTeste']->add($this->widgets['fixTeste']);
		
		$this->widgets['frmTeste']->set_name("frmTeste");

		// Conecta o destroy
		$this->widgets['frmTeste']->connect(
			"destroy", 
			array("Gtk", "main_quit")
		);

		// Add css style
		$css_provider = new GtkCssProvider();
		$css_provider->load_from_data("
			#frmTeste {
				background: white;
			}

			#eventb {
				background: #ff0000;
				border: 0px;
				border-radius: 0px;
			}
			
			#eventb:hover {
				background-color: purple;
				-unico-inner-stroke-width: 0;
			}
			
			#eventb:active {
				background-color: gray;
				-unico-inner-stroke-width: 0;
			}
		");
		
		$style_context = $this->widgets['frmTeste']->get_style_context();
		$style_context->add_provider($css_provider, 600);
		
		$style_context = new GtkStyleContext();
		$style_context->add_provider($css_provider, 1000);
		
		$style_context->add_provider_for_screen($css_provider, 600);

		// $this->widgets['frmTeste']->set_interactive_debugging(TRUE);

		$this->widgets['evtTeste']->add_events(1 << 2);
		$this->widgets['frmTeste']->show_all();
	}
}

// Inicia a aplicação
$teste = new Teste();
gtk::main();