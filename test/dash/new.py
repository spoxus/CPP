from   dash import Dash, dcc, html, Input, Output
from   jupyter_dash import JupyterDash
import plotly.graph_objects as go
import pandas as pd

# app instantiation
# app = Dash(__name__)
app = JupyterDash(__name__)

fig  = go.Figure()
# add a scatter trace

x = [2,4,6]
y = [10,3,6]
data = pd.DataFrame(y, index = x)

fig.add_scatter(
    data,
    name = 'bid',
)
# add another scatter trace

fig.add_scatter(
    x = [4,6,8],
    y = [20,10,15],
    name = 'ask',
)

# app layout: a list of HTML and /or interactive components

app.layout = html.Div([
    html.H1('Hello, World!'),
    dcc.Dropdown(id='names_dropdown',
                 options=[{'label': name, 'value': name}
                          for name in ['John', 'Joe', 'Jane']]),
    html.Br(),
    html.Div(id='names_output', children='blank'),
    dcc.Graph(
        id='example-graph',
        figure=fig,
    ),
])

# callback functions
@app.callback(
    Output('names_output', 'children'),
    [Input('names_dropdown', 'value')],
)
def display_selected_name(name):
    if name is None:
        name = 'nobody'
    return 'You selected ' + name

@app.callback(
    Output('example-graph', 'children'),
    [Inout('', '')],
)
def append_data():
    pass

if __name__ == '__main__':
    app.run_server(debug=True)