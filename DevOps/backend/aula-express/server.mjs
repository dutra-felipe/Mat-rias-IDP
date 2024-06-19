import express, { json } from "express";
import contatos from "./Data/contatos.mjs";

const app = express();

app.use(express.json());

app.get('/', (req, res) => {
    res.send(`Olá ${req.query.nome}!`);
});

//GET: /contatos
app.get('/contatos', (req, res) => {
    res.status(200).json(contatos)
});

//GET: /contatos/:id
//:id (params.id)
app.get("/contatos/:id", (req, res) =>{
    const id = req.params.id;
    const sit = req.query.sit;
    console.log(id, sit);
    const contato = contatos.find((contato) => contato.id == id);
    if(!contato){
        return res.status(404).json({
            mensagem: "Contato não encontrado!"
        });
    }
    return res.json({
        id: id,
        nome: contato.nome
    });
});

//POST: /contatos
app.post("/contatos", (req, res) => {
    const contato = req.body;
    if(!contato || !contato.nome || !contato.genero || !contato.telefone || !contato.email){
        return res.status(400).json({
            error: true,
            mensagem: "Dados inválidos"
        });
    }
    const email_existe = contatos.find(c => {
        return c.email == contato.email
    });
    if (email_existe){
        return res.status(400).json({
            error: true,
            message: "Email já cadastrado!"
        });
    }
    if (contatos.length == 0){
        contato.id = 1;
    } else contato.id = contatos[contatos.length-1].id + 1;
    contatos.push(contato);
    res.status(201).json({
        contato: contato
    })
});

//PUT: /contatos/:id
app.put("/contatos/:id", (req, res) => {
    const id = req.params.id;
    const contato = req.body;
    if(!contato || !contato.nome || !contato.genero || !contato.telefone || !contato.email){
        return res.status(400).json({
            mensagem: "Dados inválidos"
        });
    }
    contato.id = id;
    const index = contatos.findIndex((contato) => contato.id == id);
    if(index < 0){
        return res.status(404).json({
            mensagem: "Contato não encontrado!"
        });
    }
    contato[index] = contato;
    res.json({
        mensagem: "Contato atualizado com sucesso!",
        contato: contato
    });
});

const porta = 3000, host = "127.0.0.1";
app.listen(porta, host, () =>{
    console.log(`Servidor iniciado em ${host}:${porta}`);
});

